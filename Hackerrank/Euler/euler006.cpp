#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
typedef long long int lli;

lli getDiff(lli n)
{
	lli s = (n*(n+1)*(3*n*n-n-2))/12;
	return s;
}

int main()
{
	lli t,n;
	getLong(t);
	while(t--)
	{
		getLong(n);
		printf("%lld\n",getDiff(n));
	}
	return 0;
}