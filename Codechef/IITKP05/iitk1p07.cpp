#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0;i<n;i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define g(n) scanf("%lld",&n)

lli power(lli n, lli p)
{
	if(p==0) return 1;
	lli a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a*=sq;
		sq*=sq;
		p = p>>1;
	}
	return a;
}

lli power_mod(lli n, lli p, lli modulo)
{
	if(p==0) return 1%modulo;
	lli a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}

lli compute(lli x, lli m, lli n)
{
	if(m==0)
		return 1;
	else if(m&1)
	{
		lli t = compute(x,m/2,n);
		lli ans = t*(com)
	}
}

int main()
{
	lli t,x,n,m;
	g(t);
	while(t--)
	{
		g(x),g(n),g(m);

	}
}