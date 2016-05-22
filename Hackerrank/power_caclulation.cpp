#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,n) for(ll i=0;i<n;i++)
#define g(n) scanf("%lld",&n)

// n^p mod modulo
ll power_mod(ll n, ll p, ll modulo)
{
	if(p==0) return 1%modulo;
	ll a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}
ll ar[100];
ll sum;
void init(ll n)
{
	f(i,100) 
	{
		ar[i] = power_mod(i,n,100);
		sum+=ar[i];
	}
}

int main()
{
	ll t,n,k;
	g(t);
	while(t--)
	{
		g(k), g(n);
		sum=0;
		init(n);
		ll ans = 0;
		ll q = k/100, r = k%100;
		ans = (q*sum)%100;
		f(i,r+1)
		ans+=ar[i];
		ans%=100;
		if(ans<10)
			printf("0%lld\n",ans);
		else
			printf("%lld\n",ans);
	}
	return 0;
}