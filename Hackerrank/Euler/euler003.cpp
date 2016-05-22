// largest prime factor
#include <iostream>
#include <stdio.h>

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
typedef long long int lli;

lli getMaxPrimeFactor(lli n)
{
	lli max = 1;
	for(lli i=2; i*i <= n; i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
			}
			if(i>max)
				max=i;
		}
	}

	if(n!=1)
		max = n;
	return max;
}

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		lli n;
		getLong(n);
		printf("%lld\n",getMaxPrimeFactor(n));
	}
	return 0;
}