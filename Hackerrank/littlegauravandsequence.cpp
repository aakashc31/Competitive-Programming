#include <stdio.h>
#include <cstring>
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;


lli log2(lli s)
{
	lli p=0;
	while(s!=1)
	{
		p++;
		s/=2;
	}
	return p;
}

int main()
{
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		lli k=log2(n);
		lli p1,p2;
		if(k==0)
			p1=2;
		else 
			p1 = (6*k)%10;
		if(n%2==0)
			p2 = 1;
		else
			p2 = 5;
		p1 = (p1*p2)%10;
		printf("%lld\n",p1);
	}
	return 0;
}
