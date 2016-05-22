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


int main()
{
	int n = inputInteger();
	while(n!=0)
	{
		
		int num = (n*(n+1)*(2*n+1))/6;
		printf("%d\n",num);
		n =inputInteger();
	}
	return 0;
}