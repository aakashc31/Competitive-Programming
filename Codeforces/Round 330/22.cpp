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

ll power10(int k){
	ll ret = 1;
	f(i,k) ret *= 10;
	return ret;
}

ll numDiv(int k, int a, int x){
	x %= a;
	ll high = power10(k) - 1;
	ll ans = ((high - x) / a) + 1;
	return ans;
}

ll compute(int a, int b, int k){
	if(a == 1){
		if(k != 1){
			return (power10(k) - power10(k-1));
		}
		else{
			return 9;
		}
	}
	if(k == 1){
		if(a > 9){
			return (b==0) ? 0 : 1;
		}
		if(a==b || 0==b)
			return 1;
		else
			return 2;
	}
	ll tot = numDiv(k, a, 0);
 	ll frem = (a - ((b * power10(k-1))%a)) % a;
	ll sub = numDiv(k-1, a, frem);
	// cout << "a = " << a << " b = " << b << " tot = " << tot << " frem = " << frem << " sub = " << sub << endl;
	return tot-sub;
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