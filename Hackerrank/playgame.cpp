#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)

lli ar[100000];
lli sum_ar[100000];
lli ans[100000];
lli n;
lli max_optimal_score(int i)
{
	if(i>=n-3)
		return sum_ar[i];
	if(ans[i]!=-1)
		return ans[i];
	lli ret = ar[i] + sum_ar[i+1] - max_optimal_score(i+1);
	ret = max(ret, ar[i]+ar[i+1] + sum_ar[i+2] - max_optimal_score(i+2));
	ret = max(ret, ar[i]+ar[i+1] + ar[i+2] + sum_ar[i+3] - max_optimal_score(i+3));
	ans[i] = ret;
	return ret;
}
int main()
{
	lli t;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]), ans[i]=-1;
		lli tot = 0;
		for(int i=n-1; i>=0; i--)
		{
			tot+=ar[i];
			sum_ar[i] = tot;
		}
		printf("%lld\n",max_optimal_score(0));
	}
	return 0;
}