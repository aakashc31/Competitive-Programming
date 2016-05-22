#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

ll dp[65][10];
ll ans[65];

void pre(){
	for(int i=0; i<10; i++)
		dp[1][i] = 1;
	ans[1] = 10;
	for(int n = 2; n <= 64; n++){
		for(int i=0; i<=9; i++){
			for(int k=i; k<=9; k++)
				dp[n][i] += dp[n-1][k];
			ans[n] += dp[n][i];
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	pre();
	int t,x,y; cin >> t;
	while(t--){
		cin >> x >> y;
		cout << x << " " << ans[y] << endl;
	}
	return 0;
}