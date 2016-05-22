#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)
typedef long long int lli;

lli nct(lli n)
{
	if(n<2)
		return 0;
	return (n*(n-1))/2;
}

int main()
{
	lli t,n,a,n1,n2;
	g(t);
	while(t--)
	{
		g(n);
		n1 = 0, n2 = 0;
		f(i,n)
		{
			g(a);
			if(a==1) n1++;
			else if(a==2) n2++;
		}
		lli ans = 2*(nct(n1)) + nct(n2) + n1*(n-n1);
		printf("%lld\n",ans);
	}
	return 0;
}