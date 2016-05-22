#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	int t,n,r,q,ans;
	g(t);
	while(t--)
	{
		g(n);
		q = n/2048;
		r = n%2048;
		ans = q + __builtin_popcount(r);
		printf("%d\n",ans);
	}
	return 0;
}