#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const ll mod = 1e9 + 7;
ll power_mod(ll x, ll p){
	if(p==0)
		return 1;
	ll sq = power_mod(x,p>>1);
	sq = (sq*sq)%mod;
	if(p&1)
		sq = (sq * x)%mod;
	return sq;
}

ll compute(int n, int m){
	if(n==1)
		return m;
	if(n==2)
		return (m*1ll*(m-1))%mod;
	ll ans = (m*1ll*(m-1))%mod;
	ans = (ans * power_mod(m-2, n-2)) % mod;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		cout << compute(n,m) << endl;
	}
	return 0;
}