#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)
const lli modulo = 1000000007;

lli extended_euclid(lli a, lli b, lli &x, lli &y) 
{  
  lli xx = y = 0;
  lli yy = x = 1;
  while (b) 
  {
    lli q = a/b;
    lli t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
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

int main()
{
	lli t,a,b,x,inv,y;
	g(t);
	while(t--)
	{
		g(a),g(b),g(x);
		if(b>=0)
			printf("%lld\n",power_mod(a,b,x));
		else
		{
			extended_euclid(a,x,inv,y);
			if(inv < 0)
				inv = ((x-1)*(-inv))%x;
			else
				inv %= x;
			printf("%lld\n",power_mod(inv,-b,x));
		}
	}
	return 0;
}