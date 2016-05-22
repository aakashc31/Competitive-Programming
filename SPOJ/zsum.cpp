#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;


const int modulo = 10000007 ;

ll power_mod(ll n, ll p){
	ll sq = n;
	ll ans = 1;
	while(p > 0){
		if(p & 1)
			ans = (ans * sq) % modulo;
		sq = (sq * sq) % modulo;
		p >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	ll n,k;
	while(1){
		cin >> n >> k;
		if(n==0 && k == 0)
			break;
		ll ans = 0;
		ans = (ans + power_mod(n,n)) % modulo;
		ans = (ans + power_mod(n,k)) % modulo;
		ans = (ans + 2*power_mod(n-1,n-1)) % modulo;
		ans = (ans + 2*power_mod(n-1,k)) % modulo;
		cout << ans << endl;
	}
	return 0;
}