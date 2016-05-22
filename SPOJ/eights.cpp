#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%lld",&n)

int main()
{
	int ar[] = {192,442,692,942};
	long long int k,t;
	getNum(t);
	while(t--)
	{
		getNum(k);
		if(k<=4)
			printf("%d\n",ar[k-1]);
		else
		{
			long long int tmp = (k-1)/4;
			printf("%lld%d\n",tmp,ar[(k-1)%4]);
		}
	}
	return 0;
}