#include <stdio.h>
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%lld",&n)
typedef unsigned long long int lli;
lli nc2(int n)
{
	if(n<=1)
		return 0;
	lli i = n;
	i = (i*(i-1))/2;
	return i;
}
lli ar[1000000];
int  main()
{
	ar[0] = 1;
	for(lli i=1;i<1000000;i++)
	{
		lli n=i+1;
		ar[i] = ar[i-1] + ((n*(n+1))/2 )+ n - 1 + nc2(n-2);
	}
	lli t;
	getNum(t);
	while(t--)
	{
		lli n;
		getNum(n);
		printf("%lld\n",ar[n-1]);
	}
	return 0;
}
