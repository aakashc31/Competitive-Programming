#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int dp[100][100];
int main()
{
	int n,m;
	g(n), g(m);
	f(i,n)
	{
		f(j,m)
		{
			g(dp[i][j]);
		}
	}
	fab(i,1,n-1)
	{
		f(j,m)
		{
			int up_right = (j==m-1)?INT_MAX : dp[i-1][j+1];
			int up_left = (j==0)?INT_MAX : dp[i-1][j-1];
			dp[i][j] = min(min(up_left,up_right), dp[i-1][j]) + dp[i][j];
		}
	}
	int ans = dp[n-1][0];
	fab(j,1,m-1)
		ans = min(ans, dp[n-1][j]);
	printf("%d\n",ans);
	return 0;
}