#include <stdio.h>
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%lld",&n)
typedef unsigned long long int lli;

int main()
{
	lli n;
	getNum(n);
	while(n%2==0)
		n/=2;
	if(n==1)
		printf("TAK\n");	
	else
		printf("NIE\n");
	return 0;
}	