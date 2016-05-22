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

int func(int x)
{
	if(x%2==0)
		return 2*(x-2)+2;
	else
		return 2*(x-3)+3;
}

int main()
{
	int t,x,y;
	t = inputInteger();
	while(t--)
	{
		x = inputInteger(), y = inputInteger();
		if(x==0 && y==0)
			printf("0\n");
		else if(x==1 && y==1)
			printf("1\n");
		else if(x<2)
			printf("No Number\n");
		else
		{
			if(y==x-2)
				printf("%d\n",func(x));
			else if(y==x)
				printf("%d\n",func(x)+2);
			else
				printf("No Number\n");
		}
	}
	return 0;
}