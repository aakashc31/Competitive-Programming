#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

#define f(i,n) for(ll i=0; i<n; i++)
#define fab(i,a,b) for(ll i=a; i<=b; i++)
#define mp make_pair
#define pb push_back

ll dp[251][50];
ll c[50];

ll compute(ll i, ll j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i<0) return 0;
	if(i==0) return 1;
	
	if(j==0)
	{
		if(i%c[j]==0)
			return 1;
		else
			return 0;
	}

	dp[i][j] = compute(i,j-1);
	for(ll k=1; k<= (i/c[j]); k++)
	{
		dp[i][j] += compute(i-k*c[j], j-1);
	}
	return dp[i][j];
}

int main()
{
	ll n,m;
	cin >> n >> m;
	f(i,m) cin >> c[i];
	f(i,251)
		f(j,50)
			dp[i][j] = -1;

	sort(c,c+m);
	cout << compute(n,m-1) << endl;
	return 0;
}