#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)
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



int power10(int k)
{
	int r = 1;
	while(k--)
		r*=10;
	return r;
}
// returns the first k digits of n
int getfirstk(long long int n,int k)
{
	int num = ceil(log10(n)); //number of digits in n
	if(num<=k)
		return n;
	else
	{
		int p = n/power10(num-k);
		return p;
	}
}

int firstk(int n, int p, int k)
{
	int numdig = ceil(float(p)*(log10(n)));
	if(numdig<=k)
		return (int)(pow(n,p));
	else
	{
		if(p%2==0)
		{
			int a = firstk(n,p/2,k+2);
			long long int b = ((long long int)(a))*a;
			int r = getfirstk(b,k);
			return r;
		}
		else
		{
			int a = firstk(n,p/2,k+1);
			long long int b = ((long long int)(a))*a;
			int c = getfirstk((long long int)(n),k);
			int d = getfirstk(b,k);
			return getfirstk(((long long int)(c))*d,k);
		}
	}
}

int lastk(int n, int p, int k)
{
	int numdig = ceil(float(p)*(log10(n))); //num digits in n^p
	if(numdig<=k)
		return (int)(pow(n,p));
	else
	{
		if(p%2==0)
		{
			int a = lastk(n,p/2,k);
			long long int b = ((long long int)(a))*a;
			int r =  b%(power10(k));
			return r;
		}
		else
		{
			int a = lastk(n,p/2,k);
			long long int b = a*a;
			int r = ((b%power10(k))*n)%power10(k);
			return r;
		}
	}
}

int main()
{
	int t = inputInteger();
	while(t--)
	{
		int n = inputInteger(), k = inputInteger();
		//print first k digits of  n^n
		printf("%d %d\n",firstk(n,n,k), lastk(n,n,k));
	}
	return 0;
}