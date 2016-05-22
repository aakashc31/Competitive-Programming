#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
// use 0-1 knapsack

int dp[101][501];
int wt[101], val[101];
int main()
{
	int budet, nump, a,b;
	g(budet),g(nump);
	while(true)
	{
		if(budet==0 && nump==0)
			break;
		f(i,nump) g(wt[i+1]), g(val[i+1]);

		int money = 5000, fun = 0;
		for(int i=0; i<=nump; i++)
		{
			for(int w=0; w<=budet; w++)
			{
				if(i==0 || w==0) 
					dp[i][w] = 0;
				else
				{
					if(wt[i] > w)
						dp[i][w] = dp[i-1][w];
					else
					{
						dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i]);
						if(dp[i][w] > fun)
							fun = dp[i][w], money = w;
						else if(dp[i][w] == fun && w<money)
							money=w;
					}
				}
			}
		}
		printf("%d %d\n",money,fun);
		g(budet),g(nump);
	} 
	return 0;
}