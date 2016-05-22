#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0 ;i<n; i++)
const int MAXSIZE = 100000;
#define g(n) scanf("%d",&n)

// prints integer represented by ar, assuming little endian form, and max size of l
void print_array(int ar[], int l)
{
	while(ar[l]==0)
		l--;
	while(l>=0)
		printf("%d",ar[l]), l--;
	printf("\n");
}

void add_arrays(int a[], int b[], int s[], int size)
{
	int carry = 0;
	f(i,size)
	{
		int temp = a[i] + b[i] + carry;
		s[i] = temp%10;
		carry = temp/10;
	}
}

void subtract(int a[], int b[], int d[], int size)
{
	int carry = 0;
	f(i,size)
	{
		int diff = a[i] - b[i] - carry;
		if(diff < 0)
		{
			diff+=10;
			carry = 1;
			d[i] = diff;
		}
		else
		{
			d[i] = diff;
			carry = 0;
		}
	}
}

void multiply_by_const(int ar[], int size, int num)
{
	int carry = 0;
	f(i,size)
	{
		int t = ar[i]*num + carry;
		ar[i] = t%10;
		carry=t/10;
	}
}

int get_mod(int ar[], int i, int j, int b)
{
	if(i==j)
		return ar[j]%b;
	else
		return (ar[i] + 10*get_mod(ar,i+1,j,b))%b;
}

void store(int ar[], int size, int n)
{
	int i=0;
	while(n>0)
	{
		ar[i++] = n%10;
		n/=10;
	}
	while(i<size)
		ar[i]=0;
}
int ar[100000];
vector<int*> sink;
int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		int q = __gcd(ar[0],ar[1]);
		for(int i=2;i<n;i++)
			q = __gcd(ar[i],q);
		if(q>1)
		{
			printf("-1\n");
			continue;
		}
		int maxl = 1;
		int* pdt = new int[MAXSIZE];
		store(pdt,MAXSIZE,ar[0]);
		sink.push_back(pdt);
		int* curr = pdt;
		for(int i=1;i<n;i++)
		{
			if(__gcd(get_mod(curr,0,MAXSIZE-1,ar[i]), ar[i]) == 1)
			{
				int* new_curr = new int[MAXSIZE];
				f(i,MAXSIZE) new_curr[i] = curr[i];
				multiply_by_const(new_curr,MAXSIZE,ar[i]);
				sink.push_back(new_curr);
				maxl++;
				if(maxl>tot)
					tot = maxl;
			}
			else
			{
				for(int j = i-maxl; j<i; j++)
				{
					
				}
			}
		}
	}
	return 0;
}