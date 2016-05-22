#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,n) for(ll i=0;i<n;i++)
#define g(n) scanf("%lld",&n)
const ll modulo = 1000007;
int main()
{
	ll t,n;
	g(t);
	while(t--)
	{
		g(n);
		ll ans = (n*(n-1))/2; ans%=modulo;
		ans += (n*(n+1))%modulo;
		ans%=modulo;
		printf("%lld\n",ans);
	}
	return 0;
}