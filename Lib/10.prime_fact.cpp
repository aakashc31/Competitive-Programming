#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)


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
