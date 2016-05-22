#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int dp[2010][2010];

int lcs(vi& u, vi& v){
	dp[0][0] = (u[0] == v[0]) ? 1 : 0;
	int m = u.size(), n = v.size();
	for(int i=1; i<m; i++)
		dp[i][0] = (dp[i-1][0] == 1) ? 1 : (u[i] == v[0] ? 1 : 0);
	for(int j=1; j<n; j++)
		dp[0][j] = (dp[0][j-1] == 1) ? 1 : (u[0] == v[j] ? 1 : 0);
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dp[i][j] = (u[i] == v[j]) ? (1 + dp[i-1][j-1]) : (max(dp[i-1][j], dp[i][j-1]));
		}
	}
	return dp[m-1][n-1];
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		vi u(0);
		int x; cin >> x;
		while(x != 0){
			u.pb(x); cin >> x;
		}
		int y; cin >> y; vi v(0); int ans = 0;
		while(y != 0){
			v.pb(y);
			cin >> x;
			while(x != 0){
				v.pb(x); cin >> x;
			}
			ans = max(ans, lcs(u,v));
			v.resize(0); cin >> y;
		}
		cout << ans << endl;
	}
	return 0;
}