#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
const int modulo = 1000000007;
typedef long long int lli;

lli ar[100001];

lli get(int n, int k)
{
	lli d = n/k;
	lli ans = 1 + d*(n+1) - k*((d*(d+1))/2);
	return ans;	
}

void init(int k)
{
	ar[0] = 0;
	for(int i=1; i<=100000;i++)
		ar[i] = (ar[i-1] + get(i,k));
}

int main()
{
	int t,k,a,b;
	g(t),g(k);
	init(k);
	f(i,t)
	{
		g(a),g(b);
		lli ans = (ar[b] - ar[a-1])%modulo;
		printf("%lld\n",ans);
	}
	return 0;
}