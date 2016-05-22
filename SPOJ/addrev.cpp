#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)

int inputInteger()
{
	char ch = inpch;
	register int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = (r<<1) + (r<<3) + ch-'0';
		ch = inpch;
	}
	return r;
}

int rev(int n)
{
	int k = 0;
	while(n!=0)
	{
		int d = n%10;
		n/=10;
		k = k*10 + d;
	}
	return k;
}

int main()
{
	int t,n1,n2,s;
	t = inputInteger();
	while(t--)
	{
		n1 = rev(inputInteger());
		n2 = rev(inputInteger());
		printf("%d\n",rev(n1+n2));
	}
	return 0;
}