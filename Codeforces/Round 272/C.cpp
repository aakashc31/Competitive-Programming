#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%lld",&n)
const long long int modulo = 1000000007;
typedef long long int lli;
const lli inv = 500000004;

lli partfunc(lli a, lli b, lli r)
{
	lli armod = (a*r)%modulo;
	lli ans = ((b*(a+1))/2 + 1)%modulo;
	ans = (ans*armod)%modulo;
	return ans;
}

int main()
{
	lli a,b;
	g(a),g(b);
	lli s = 0;
	for(lli r = 1; r<=b-1; r++)
	{
		s += partfunc(a,b,r);
		s%=modulo;
	}
	printf("%lld\n",s);
	return 0;
}