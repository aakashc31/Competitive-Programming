#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define get(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)

lli count(lli n)
{
	lli cpy = n;
	lli s=0;
	while(n>0)
	{
		lli d = n%10;
		n/=10;
		if(d!=0 && cpy%d==0)
			s++;
	}
	return s;
}

int main()
{
	lli t,n;
	get(t);
	while(t--)
	{
		get(n);
		printf("%lld\n",count(n));
	}
	return 0;
}