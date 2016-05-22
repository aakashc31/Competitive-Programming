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


int main(){
	ios::sync_with_stdio(false);
	int n,a; cin >> n;
	bool flag = false;
	for(int i=0; i<n; i++){
		cin >> a;
		if(a&1) flag = true;
	}
	ll ans = 0;
	if(flag)
		ans = power_mod(2,n-1);
	else
		ans = power_mod(2,n);
	ans = (ans + mod - 1) % mod;
	cout << ans << endl;
	return 0;
}