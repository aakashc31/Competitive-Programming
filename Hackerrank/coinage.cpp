#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;
const int maxn = 1e3+1;
int dp[maxn][4];
int a[4], d[4], n;

void compute(){
	for(int i=0; i<=n; i++){
		dp[i][0] = (i<=a[0]) ? 1 : 0;
		for(int k=1; k<=3; k++){
			dp[i][k] = 0;
			for(int j=0; j<=a[k]; j++){
				dp[i][k] += (i-d[k]*j >= 0) ? dp[i-d[k]*j][k-1] : 0;
			}
		}
		// cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
	}
	cout << dp[n][3] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t; d[0] = 1, d[1] = 2, d[2] = 5, d[3] = 10;
	while(t--){
		cin >> n;
		for(int i=0; i<4; i++) cin >> a[i];
		compute();
	}
	return 0;
}