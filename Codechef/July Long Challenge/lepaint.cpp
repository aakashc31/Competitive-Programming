// changed all float to double and it fuckinggggggggggggggg worked... I don't know if I am happy or sad!

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
typedef long long int lli;
int counter[50];
double expec[51];
double probable_expec[51];
lli ncr(long n, long r)
{
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	long long s = 1.0;
	int aa = n-r+1;
	f(i,r)
	{
		s = s*(aa+i)/(i+1);
	}
	// long long int a =s;
	return s;
}

void print_array(lli ar[], int left, int right)
{
	for(int i=left; i<=right;i++)
		printf("%lld, ", ar[i]);
	printf("\n");
}

// this function computes the expectation color after l paintings
void compute_expectations(int c, int k)
{
	expec[0] = 1.0;
	expec[1] = (c-1.0)/2.0;
	double ar[c]; //ar[i] = number of times i'th color appears after 2 paintings, considering all possiblities
	f(i,c)
		ar[i]=0.0;
	for(int i=1; i<c; i++)
	{
		for(int j=0; j<c; j++)
		{
			int p = (i*j)%c;
			ar[p] += 1.0/(c*c);
		}
	}
	// now we calculate expec[2]
	double s=0;
	for(int i=1; i<c; i++)
	{
		s+= (i*ar[i]);
	}
	// printf("For k = 2: ");
	// print_array(ar,0,c-1);
	expec[2] = s;
	// printf("Expec[%d] = %f\n",2,expec[2]);
	// this was somehow my base case.

	// now move to induction step
	// for each m we calculate the expec[m]
	for(int m=3; m<=k; m++)
	{
		double tempar[c];
		f(i,c)
			tempar[i]=0.0;
		for(int i=1; i<c; i++)
		{
			for(int j=1; j<c; j++)
			{
				int p = (i*j)%c;
				tempar[p]+=(ar[i]/c);
			}
		}
		s=0.0;
		f(i,c) 
		{
			s += i*tempar[i];
			ar[i] = tempar[i];
		}
		// printf("For k = %d: ",m);
		// print_array(ar,0,c-1);

		expec[m] = s;
		// printf("Expec[%d] = %f\n",m,expec[m]);
	}
}


void getAllExpectedColors(int k)
{
	probable_expec[0] = 1.0;
	probable_expec[1] = 0.5 + 0.5*expec[1];
	for(int i=2; i<=k; i++)
	{
		// we are computing probable expectation of i
		double power2 = pow(2,i); //2^i
		double s=0.0;
		for(int j=0;j<=i;j++)
		{
			lli comb = ncr(i,j);
			double t = (double(comb))/power2;
			s += t*expec[j];
		}
		probable_expec[i] = double(s);
		// printf("prob_exp[%d] = %.9f\n",i,probable_expec[i]);
	}
}

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n,c,k;
		getNum(n);
		getNum(c);
		getNum(k);
		compute_expectations(c,k);

		getAllExpectedColors(k);
		f(i,n)
			counter[i]=0;
		f(i,k)
		{
			int l,r;
			getNum(l);getNum(r);
			for(int j=l-1; j<r;j++)
				counter[j]++;
		}
		//input khatm
		
		double ans = 0.0;
		f(i,n)
		{
			ans+= probable_expec[counter[i]];
		}
		printf("%.9f\n", ans);
	}
	return 0;
}

