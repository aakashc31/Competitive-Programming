#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
// use 0-1 knapsack
int money, fun;
int dp[501];
int wt[101], val[101];
int n;
int solve_knapsack(int w)
{
	if(w<=0)
		return 0;
	if(dp[w]!=-1)
		return dp[w];
	f(i,n)
	{
		if(wt[i+1] <= w)
		{
			dp[w] = max(dp[w], solve_knapsack(w-wt[i+1])+val[i+1]);
		}
	}
	// if(dp[w] > fun)
	// 	fun = dp[w], money = w;
	// else if(dp[w]==fun && w<money)
	// 	money = w;
	return dp[w];
}

int main()
{
	int budet, nump, a,b;
	g(budet),g(nump);
	while(true)
	{
		if(budet==0 && nump==0)
			break;
		f(i,nump) g(wt[i+1]), g(val[i+1]);
		n = nump;
		money = 5000, fun = 0;
		f(i,budet+1) dp[i]=-1;
		solve_knapsack(budet);
		// printf("%d %d\n",money,fun);
		printf("%d\n",dp[budet]);
		g(budet),g(nump);
	} 
	return 0;
}