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

void inputString()
{
	char ch = inpch;
	while(ch=='\n' || ch==' ') ch = inpch;

	int numz = 0; long long int sum = 0;
	while(ch!='\n' && ch!=' ')
	{
		if(ch=='1')
		{
			numz++;
			sum+=numz;
		}
		ch = inpch;
	}
	printf("%lld\n",sum);
}

int main()
{
	int t = inputInteger();
	while(t--)
	{
		int n = inputInteger();
		inputString();
	}
	return 0;
}