#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int modulo = 1e9+7;
const int maxn = 101;

ll dp[maxn][maxn];
void pre(){
	for(int i=1; i<maxn; i++){
		 dp[1][i] = i+1; dp[i][1] = i+1;
	}
	for(int n=2; n<maxn; n++){
		for(int r=2; r<maxn; r++)
			dp[n][r] = (dp[n][r-1] + dp[n-1][r]) % modulo;
	}
}

int main(){
	ios::sync_with_stdio(false);
	pre();
	int t,n,m; cin >> t;
	while(t--){
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}
	return 0;
}