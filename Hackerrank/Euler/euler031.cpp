#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0;i<n;i++)
#define g(n) scanf("%lld",&n)
typedef long long int lli;
const lli modulo = 1000000007;
lli g[6][100001];
lli denom[] = {5,10,20,50,100,200};

lli compute(lli i, lli r)
{
	if(r==2)
		return ((i/2)+1);
	if(g[r-3][i] != -1)
		return g[r-3][i];
	//else we'll have to compute
	if(i==0)
		return 1;
	if(i<0)
		return 0;
	lli t = (compute(i-denom[r-3], r) + compute(i,r-1))%modulo;
	g[r-3][i] = t;
	return t;
}

int main()
{
	f(i,100001) 
	{
		f(j,6) g[j][i] = -1;
	}
	lli t,n;
	g(t);
	while(t--)
	{
		g(n);
		printf("%lld\n",compute(n,8));
	}
	return 0;
}