#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)

int main()
{
	lli t,n,tmp,gk,kk=8;
	g(t);
	while(t--)
	{
		g(n);
		tmp = n*(n-1);
		gk = __gcd(tmp,kk);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		printf("%lld/%lld\n",tmp/gk,8/gk);
	}
	return 0;
}