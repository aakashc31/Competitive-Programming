#include <stdio.h>
#define f(i,n) for(i=0;i<n;i++)
#define g(n) scanf("%d",&n)

int dp[100][100];
int ar[100][100];

int max(int a, int b)
{
	return (a>b?a:b);
}

int main()
{
	int t,h,w,i,j;
	g(t);
	while(t--)
	{
		g(h),g(w);
		f(i,h){ f(j,w) g(ar[i][j]);}
		f(i,h)
		{
			f(j,w)
			{
				if(i==0)
					dp[i][j] = ar[i][j];
				else
				{
					int ul = (j==0)?0:dp[i-1][j-1];
					int ur = (j==w-1)?0:dp[i-1][j+1];
					int up = dp[i-1][j];
					up = max(up,ul);
					up = max(up,ur);
					dp[i][j] = up+ar[i][j];
				}
			}
		}
		int ans = 0;
		f(j,w)
			ans = max(ans, dp[h-1][j]);
		printf("%d\n",ans);
	}
	return 0;
}