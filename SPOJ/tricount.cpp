#include <stdio.h>
#define g(n) scanf("%lld",&n)
typedef unsigned long long int lli;

lli ar[1000000];


void init()
{
	ar[0] = 1;
	for(lli i=2; i<=1000000;i++)
	{
		lli j = i-1;
		lli off = 0;
		if(i&1)
		{
			off = (i*i-1)/4;
		}
		else
			off = (i*i)/4;
		ar[j] = ar[j-1] + (i*(i+1))/2 + off; 
	}
}

int  main()
{
	init();
	lli t;
	g(t);
	while(t--)
	{
		lli n;
		g(n);
		printf("%lld\n",ar[n-1]);
	}
	return 0;
}