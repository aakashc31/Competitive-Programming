#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
typedef long long int lli;

lli ar[40];

lli gcd(lli a, lli b)
{
	if(b==0)
		return a;
	else 
		return gcd(b, a%b);
}

lli lcm(lli a, lli b)
{
	lli ret = (a*b)/(gcd(a,b));
	return ret;
}

void fill_lcms()
{
	ar[0] = 1;
	ar[1] = 2;
	ar[2] = 6;
	for(lli i=4; i<=40; i++)
	{
		lli prevLcm = ar[i-2];
		ar[i-1] = lcm(prevLcm, i);
	}
}

int main()
{
	fill_lcms();
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%lld\n",ar[n-1]);
	}
	return 0;
}