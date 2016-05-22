#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

//returns max(k) such that k(k+1)/2 < n
int getk(int n)
{
	int k=0;
	int s = (k*(k+1))/2;
	while(s<n)
	{
		k++;
		s = (k*(k+1))/2;
	}
	return k-1;
}

int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		int k = getk(n);
		int d = n-((k*(k+1))/2);
		if(k%2==0)
			printf("TERM %d IS %d/%d\n",n,k+2-d,d);
		else
			printf("TERM %d IS %d/%d\n",n,d,k+2-d);
	}
	return 0;
}