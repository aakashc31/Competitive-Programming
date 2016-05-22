#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar_unlocked()
#define outch putchar_unlocked
#define getNum(n) scanf("%d",&n)
int ar[100];
int sum[100];

int inputInteger()
{
	char ch = inpch;
	int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = r*10 + ch-'0';
		ch = inpch;
	}
	return r;
}

int color(int i, int j)
{
	if(i==0)
	{
		int a =  sum[j]%100;
		// printf("Color %d to %d = %d\n",i,j,a);
		return a;
	}
	else
	{
		int a = (sum[j] - sum[i-1])%100;
		// printf("Color %d to %d = %d\n",i,j,a);
		return a;
	}
}

int compute(int m[][100], int i, int j)
{
	// cout << "computing for "<<i <<", "<<j <<endl;
	// pair<int,int> p(i,j);
	// if already computed
	if(m[i][j]!=-1)
	{
		return m[i][j];
	}
	
	// if not computed
	if(i==j)
	{
		return (m[i][j] = 0);
	}
	if(i>j)
	{
		int a = compute(m,j,i);
		m[i][j] = a;
		return a;
	}
	int min = INT_MAX;
	for(int k = i; k<j; k++)
	{
		int temp = compute(m,i,k) + compute(m,k+1,j)+ color(i,k)*color(k+1,j);
		if(temp < min)
			min = temp;
		// cout << "temp = "<<temp<<endl;
	}
	m[i][j] = min;
	return min;
}


int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		int s = 0;
		f(i,n)
		{
			ar[i] = inputInteger();
			sum[i] = s+ar[i];
			// printf("sum till %d = %d\n",i,sum[i] );
			s+=ar[i];
		}
		// f(i,n)
		// 	printf("sum till %d = %d\n",i,sum[i] );
		int m[100][100];
		f(i,n)
		{
			f(j,n)
				m[i][j] = -1;
		}
		printf("%d\n",compute(m,0,n-1));
	}
	return 0;
}