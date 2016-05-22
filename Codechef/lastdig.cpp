// nice problem
// another way: use brute force for summing a to nearest mult of 10 greater than a, and from b to nearest mult of 10 less than b.
// for the rest each group of ten has sum 45.
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int sfun(int n)
{
	int s=0;
	while(n>0)
	{
		int d = n%10;
		n/=10;
		if(d%2==0)
			s+=(2*d);
		else
			s+=d;
	}
	return s%10;
}

int c(int n)
{
	if(n%10==0)
		return 45*(n/10);
	else
		return c(n-1)+sfun(n-1);
}
int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int a,b;
		getNum(a);
		getNum(b);
		int s = c(b+1)-c(a);
		printf("%d\n",s);
	}
	return 0;
}