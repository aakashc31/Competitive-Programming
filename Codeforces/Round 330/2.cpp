#include <bits/stdc++.h>
using namespace std;

#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

// number of k digit numbers which on div by a leave rem x
ll numDiv(ll k, ll a, ll x){
	if(k==0)
		return 0;
	ll ans = 1;
	for(ll i=0; i<k; i++)
		ans *= 10;
	ans--;
	if(ans < x)
		return 0;
	ll ret = ((ans-x)/a) + 1;
	return ret;
}


ll powermod(ll b, ll x,ll p, ll a){
	ll pw = 1;
	f(i,p) pw *= x;
	ll r =b*pw;
	return r % a;
}

ll compute(ll a, ll b, ll k){
	if(a == 1){
		if(k!=1){
			ll tot = numDiv(k, a, 0) - numDiv(k-1, a, 0);
			return tot;
		}
		else{
			return 9;
		}
	}
	if(k == 1){
		if(a > 9){
			return (b==0) ? 0 : 1;
		}
		ll ret = 9/a + 1;
		if(b % a == 0)
			ret--;
		return ret;
	}
	// ll tot = numDiv(k, a, 0);
 // 	ll frem = (a - powermod(b,10,k-1,a)) % a;
	// ll sub = numDiv(k-1, a, frem);
	ll tot = 0;
	for(int i=0; i<10; i++){
		if(i==b)
			continue;
		ll frem = (a - powermod(i, 10, k-1, a)) % a;
		ll sub = numDiv(k-1, a, frem);
		tot += sub;
	}
	// cout << "a = " << a << " b = " << b << " tot = " << tot << " frem = " << frem << " sub = " << sub << endl;
	return tot;
}
const ll mod = 1e9 + 7;
ll a[100000], b[100000];

int main(){
	ios::sync_with_stdio(false);
	ll n,k; cin >> n >> k;
	ll l = n/k;
	f(i,l) cin >> a[i];
	f(i,l) cin >> b[i];
	ll ans = 1;
	f(i,l){
		ans *= (compute(a[i], b[i], k));
		ans = (ans + mod) % mod;
	}
	cout << ans % mod << endl;
	return 0;
}