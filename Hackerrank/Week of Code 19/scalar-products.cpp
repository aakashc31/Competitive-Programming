#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
#define maxn 1000010

ll m;

ll operator*(const pll& a, const pll& b){
	ll ret = ((a.first * b.first) % m + (a.second * b.second) % m) % m;
	return ret;
}

int main(){
	ll c,x,n; cin >> c >> m >> n;
	vector<pll> v(n);
	pll curr = mp(0,c);
	for(int i=0; i<n; i++){
		x = (curr.first + curr.second) % m;
		v[i] = mp(x, (x + curr.second) % m);
		curr = v[i];
	}
	set<ll> S;
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	S.insert(v[0]*v[1]);
	for(int i=2; i<n; i++){
		S.insert(v[i]*v[i-1]);
		S.insert(v[i]*v[i-2]);
	}
	cout << S.size() << endl;
	return 0;
}