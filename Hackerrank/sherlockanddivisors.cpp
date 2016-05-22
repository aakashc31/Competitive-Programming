
#include <stdio.h>
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long int lli;

// returns the number of divisors of n that are divisible by 2
lli num_div(lli n)
{
	lli s=0;
	while(n%2==0)
		s++,n/=2;
	if(s==0)
		return 0;
	for(lli i=3; i*i <= n; i++)
	{
		lli i_count = 0;
		while(n%i==0)
			n/=i, i_count++;
		s = s*(1+i_count);
	}
	if(n!=1)
		s*=2;
	return s;
}

int main()
{
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%lld\n",num_div(n));
	}
	return 0;
}