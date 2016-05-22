#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int modulo = 1e9;
const int maxn = 1e3;

ll dp[maxn][maxn];
void pre(){
	for(int i=0; i<maxn; i++){
		 dp[0][i] = 0; dp[i][0] = 1;
	}
	for(int n=1; n<maxn; n++){
		for(int r=1; r<=n; r++)
			dp[n][r] = (dp[n-1][r-1] + dp[n-1][r]) % modulo;
	}
}

int main(){
	ios::sync_with_stdio(false);
	pre();
	int t,n; cin >> t;
	while(t--){
		cin >> n;
		for(int r=0; r<=n; r++)
			cout << dp[n][r] << " ";
		cout << endl;
	}
	return 0;
}