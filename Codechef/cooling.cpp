#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		int n;
		scanf("%d",&n);
		int weights[n];
		int limits[n];
		f(i,n)
			scanf("%d", weights+i);
		f(i,n)
			scanf("%d",limits+i);
		int notBaked = 0;
		sort(weights,weights+n);
		sort(limits,limits+n);
		int full = n-1;
		for(int i=n-1; i>=0; i--)
		{
			if(weights[i] > limits[full])
				notBaked++;
			else
				full--;
		}
		printf("%d\n", n-notBaked);
	}

	return 0;
}