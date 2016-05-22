// think and optimize

#include <stdio.h>
#define getNum1(n) scanf("%d",&n)
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
lli a[100001];
lli b[100001];
lli c[100001];

int main()
{
	int n,m;
	getNum1(n);
	getNum1(m);
	f(i,n)
		getNum(a[i+1]);
	f(i,m)
		getNum(b[i+1]);
	f(i,m)
		getNum(c[i+1]);
	// input over
	lli mod = 1000000007;
	for(int i=1; i<=m; i++)
	{
		lli th = b[i];
		lli ci = c[i];
		for(int j=th; j<=n; j+=th)
		{
			lli t = a[j]*c[i];
			a[j] = t%mod;
		}
	}
	f(i,n)
		printf("%lld ",a[i+1]);
	printf("\n");
	return 0;
}