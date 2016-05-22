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

int dp[10001][500];
int P[500], W[500];

int main()
{
	int t,E,F,n,weight;
	g(t);
	test(t)
	{
		g(E), g(F);
		g(n);
		f(i,n) g(P[i]), g(W[i]);
		weight = F-E;
		f(i,n) dp[0][i] = 0;
		f(i,weight+1) dp[i][0] = (i%W[0] == 0)?((i/W[0])*P[0]):INT_MAX;
		fab(w,1,weight)
		{
			fab(i,1,n-1)
			{
				dp[w][i] = dp[w][i-1];
				if(w-W[i] >= 0 && dp[w-W[i]][i]!=INT_MAX)
					dp[w][i] = min(dp[w][i], dp[w-W[i]][i] + P[i]);
				// printf("dp[%d][%d] = %d\n",w,i,dp[w][i]);
			}
		}
		if(dp[weight][n-1] == INT_MAX)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[weight][n-1]);
	}
	return 0;
}