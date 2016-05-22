#include <stdio.h>
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(i=0;i<n;i++)
typedef long long int lli;

int main()
{
	lli t;
	lli i;
	getNum(t);
	while(t--)
	{
		lli a,b,s;
		getNum(a);
		getNum(b);
		getNum(s);
		lli n = (2*s)/(a+b);
		lli d = (b-a)/(n-5);
		lli first = a - 2*d;
		printf("%lld\n",n);
		f(i,n)
		{
			printf("%lld ",first);
			first += d;
		}
		printf("\n");
	}
	return 0;
}