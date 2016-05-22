#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
const int maxn = 1010;
int dp[maxn][maxn][2]; int n;
vector<pii> q;

// ch is the bot selected for i-1th operation. x is the location of the other bot
int compute(int i, int x, int ch){
	if(i >= n) 
		return 0;
	if(dp[i][x][ch] != -1)
		return dp[i][x][ch];
	int del = abs(q[i].first - q[i].second);
	int costCh =  abs(q[i].first - q[i-1].second) + del + compute(i+1, x, ch); 
	int costNotCh = (x==0 ? 0 : abs(q[i].first - x)) + del + compute(i+1, q[i-1].second, 1-ch);
	dp[i][x][ch] = min(costCh, costNotCh);
	return dp[i][x][ch];
}

int main(){
	ios::sync_with_stdio(false);
	int t,m; cin >> t;
	while(t--){
		cin >> m >> n;
		q.resize(n);
		for(int i=0; i<n; i++)
			cin >> q[i].first >> q[i].second;
		for(int i=0; i<n; i++)
			for(int j=0; j<=m; j++)
				dp[i][j][0] = dp[i][j][1] = -1;
		int ans = abs(q[0].first - q[0].second) + compute(1, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}