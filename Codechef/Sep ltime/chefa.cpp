#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%lld",&n)
lli ar[100000];
lli n,t;
int main()
{
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		sort(ar,ar+n);
		lli ans = 0;
		for(int i=n-1;i>=0;i-=2)
			ans+=ar[i];
		printf("%lld\n",ans);
	}
	return 0;
}