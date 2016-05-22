#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef unsigned long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const ll maxn = 1e5+10;
const ll mod = 1e9 + 7;
ll fact[maxn], inv[maxn], ifact[maxn];

inline void pre(){
	fact[0] = 1; inv[1] = 1; ifact[1] = 1; ll p = mod;
	for(ll i=1; i<maxn; i++){
		fact[i] = (fact[i-1]*i)%mod;
		if(i>1){
			inv[i] = ((p - p/i)*inv[p%i])%mod;
			ifact[i] = (ifact[i-1]*inv[i])%mod;
		}
	}
}

inline ll ncr(ll n, ll r){
	if(n < 0 || r < 0)
		return 0;
	if(r > n)
		return 0;
	if(r==0 || r == n)
		return 1;
	ll ans = (fact[n] * ifact[r]) % mod;
	ans = (ans * ifact[n-r]) % mod;
	return ans;
}

int ar[100010]; int n,k;
void compute(){
	sort(ar, ar+n);
	ll ans = 0;
	for(int i=0; i<n; i++){
		ll minWala = (ncr(n-1-i, k-1) * ar[i]) % mod;
		ll maxWala = (ncr(i,k-1) * ar[i]) % mod;
		ans += (maxWala + ((mod-1)*minWala)%mod);
		ans %= mod;
	}
	cout << ans << endl;
}

int main(){
	pre();
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	compute();
	return 0;
}