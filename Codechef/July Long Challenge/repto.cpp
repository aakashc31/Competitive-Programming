#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
using namespace std;
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int mod(int x)
{
	if(x<0)
		return -1*x;
	else 
		return x;
}

int f(int x, int y)
{
	if(x==y)
		return 2*x;
	if(x==0)
	{
		if(y%2==0)
			return 2*y;
		else
			return 2*y - 1;
	}
	if(y==0)
	{
		if(x%2==0)
			return 2*x;
		else
			return 2*x + 1;
	}
	if(x>y)
		return f(x-y,0)+2*y;
	else
		return f(0,y-x)+2*x;
}

int main()
{
	int t, x, y;
	getNum(t);
	while(t--)
	{
		getNum(x);getNum(y);
		printf("%d\n",f(mod(x),mod(y)));
	}
	return 0;
}