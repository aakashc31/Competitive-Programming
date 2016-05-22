#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef unsigned long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const ll mod = 1e9+7;

ll power_mod(ll x, ll p){
	if(p == 0)
		return 1;
	ll sq = power_mod(x, p>>1);
	sq = (sq*sq) % mod;
	if(p&1) sq = (sq * x) % mod;
	return sq;
}

const int maxn = 51;
ll dp[maxn][maxn];
void pre(){
	for(int i=0; i<maxn; i++)
		dp[0][i] = 0, dp[i][0] = 1;
	for(int n=1; n<maxn; n++){
		for(int r=1; r<maxn; r++)
			dp[n][r] = (dp[n-1][r-1] + dp[n-1][r]) % mod;
	}
}

ll compute(ll m, ll n){
	ll a = max(m,n), b = min(m,n);
	if(a < 25)
		return 0;
	if(a == 25){
		if(b <= 23)
			return dp[24+b][24];
		return 0;
	}
	if(b != a-2)
		return 0;
	ll ans = (dp[48][24]*power_mod(2,b-24))%mod;
	return ans;
}

int main(){
	pre();
	ios::sync_with_stdio(false);
	ll a,b; cin >> a >> b; cout << compute(a,b) << endl;
	return 0;
}