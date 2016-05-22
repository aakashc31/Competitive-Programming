#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

#define mp make_pair
#define LSOne(n) (n & (-n))

class BIT{
private:
	vector<int> ft;
public:
	BIT(int n){
		ft.resize(n+1, 0);
	}
	inline int query(int a){
		int sum = 0;
		for(; a > 0; a -= LSOne(a))
			sum += ft[a];
		return sum;
	}
	inline int query(int a, int b){
		if(a>b) return 0;
		return query(b) - ((a==1) ? 0 : query(a-1));
	}
	inline void update(int k, int x){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] += x;
	}
};

inline ll countInversions(pli* v, int n){
	BIT* b = new BIT(n);
	ll ans = 0;
	int x;
	for(int i=0; i<n; i++){
		x = v[i].second;
		ans += b->query(x+1, n);
		b->update(x, 1);
	}
	delete b;
	return ans;
}


inline pll convert(string& st){
	ll a = 0, b = 0; int l = st.length();
	for(int i=0; i<l; i++){
		a = a*27 + (st[i] - 'a' + 1);
		b = b*27 + (st[l-1-i] - 'a' + 1);
	}
	for(int i=l; i<10; i++){
		a *= 27;
		b *= 27;
	}
	return mp(a,b);
}

pll v[100010];
pli ar[100010];

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string st;
	for(int i=0; i<n; i++){
		cin >> st;
		v[i] = convert(st);
		// cout << v[i].first << " " << v[i].second << endl;
	}
	sort(v, v+n);
	for(int i=0; i<n; i++)
		ar[i] = mp(v[i].second, i+1);
	sort(ar, ar+n);
	cout << countInversions(ar, n) << endl;
	return 0;
}