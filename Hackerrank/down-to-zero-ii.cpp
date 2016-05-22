#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int maxn = 1e6 + 5;
const int inf = 1e9;
int dp[maxn];

void pre(){
	for(int i=0; i<maxn; i++)
		dp[i] = inf;
	for(int i=0; i<=2; i++)
		dp[i]=i;
	for(int i=2; i<maxn; i++){
		//dp[i] must be computed by now.
		if(i!=maxn-1) dp[i+1] = min(dp[i]+1, dp[i+1]);
		for(int j=2; j<=i; j++){
			if(i*j >= maxn)
				break;
			dp[i*j] = min(dp[i*j], dp[i]+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	pre();
	int t,n; cin >> t;
	while(t--){
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}