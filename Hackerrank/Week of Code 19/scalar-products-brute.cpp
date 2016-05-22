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
	while(1){
		ll c,n,x; cin >> c ; 
		if(c == 0)
			break;
		cin >> m >> n;
		vector<pll> v(n);
		pll curr = mp(0,c);
		for(int i=0; i<n; i++){
			x = (curr.first + curr.second) % m;
			v[i] = mp(x, (x + curr.second) % m);
			curr = v[i];
		}
		set<ll> S;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				S.insert(v[i] * v[j]);
				// cout << v[i]*v[j] << " ";
			}
			// cout << endl;
		}
		cout << S.size() << endl;
	}
	return 0;
}