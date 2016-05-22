#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
typedef long long int lli;

int height[200000];
int dp[200000];

int absl(int a)
{
	if(a<0) return -a;
	return a;
}

int compute(int i)
{
	if(i==0) return 0;
	if(dp[i]!=-1)
		return dp[i];
	int off = 1;
	int m = INT_MAX;
	while(i-off >=0)
	{
		int k = absl(height[i]-height[i-off]) + compute(i-off);
		off = (off << 1);
		m = min(m,k);
	}
	dp[i]=m;
	return m;
}

int main()
{
	int n;
	g(n);
	f(i,n) g(height[i]);
	f(i,n) dp[i]=-1;
	printf("%d\n",compute(n-1));
	return 0;
}