#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair


ll power_mod(ll n, ll p, ll modulo)
{
	if(p==0) return 1%modulo;
	ll a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}


const ll modulo = 1e9 + 7;
inline ll inverse(ll n){
	ll p = modulo;
	return power_mod(n, p-2, p);
}

const int maxn = 1e5 + 10;
ll a[maxn];

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		ll N,x,M; cin >> N >> x >> M;
		for(int i=0; i<N; i++) cin >> a[i];
		ll ans = a[x-1] % modulo, coef = 1, temp;
		for(int i=1; i<x; i++){
			coef = (coef * ((M+i-1)%modulo))%modulo;
			coef = (coef * inverse(i)) % modulo;
			temp = (coef * (a[x-1-i] % modulo)) % modulo;
			ans = (ans + temp) % modulo;
		}
		cout << ans << endl;
	}
	return 0;
}