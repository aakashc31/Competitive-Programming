#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,n) for(ll i=0;i<n;i++)
#define g(n) scanf("%lld",&n)
ll n;
ll sum(ll n)
{
	return (n*(n+1)*(2*n+1))/6;
}
ll binary_search(ll i, ll j)
{
	ll mid = (i+j)/2;
	if(sum(mid)<=n && sum(mid+1)>n)
		return mid;
	if(sum(mid-1) <=n && sum(mid)>n)
		return mid-1;
	if(sum(mid)<=n)
		return binary_search(mid+1,j);
	else
		return binary_search(i,mid-1);
}
ll bin(ll i, ll j)
{
	if(i>=j)
		return i-1;
	ll mid = (i+j)/2;
	ll s1 = sum(mid);
	if(s1<=n)
		return bin(mid+1, j);
	else
		return bin(i,mid);
}

ll bin_iter(ll i, ll j)
{
	while(i<j)
	{
		ll mid = (i+j)/2;
		ll s1 = sum(mid);
		if(s1<=n)
			i = mid+1;
		else
			j = mid;
	}
	return i-1;
}
int main()
{
	ll t;
	g(t);
	while(t--)
	{
		g(n);
		printf("%lld\n",bin_iter(0,1000000));
	}
	return 0;
}