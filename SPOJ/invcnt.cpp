// alternate solution using BIT
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define LSOne(n) (n & (-n))

class BIT{
private:
	vector<int> ft;
public:
	BIT(int n){
		ft.resize(n+1, 0);
	}
	int query(int a){
		int sum = 0;
		for(; a > 0; a -= LSOne(a))
			sum += ft[a];
		return sum;
	}
	int query(int a, int b){
		if(a>b) return 0;
		return query(b) - ((a==1) ? 0 : query(a-1));
	}
	void update(int k, int x){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] += x;
	}
};

ll countInversions(vector<pii>& v){
	BIT* b = new BIT(v.size());
	ll ans = 0;
	for(pii& p : v){
		int x = p.second;
		ans += b->query(x+1, v.size());
		b->update(x, 1);
	}
	delete b;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pii> v(n);
		for(int i=0; i<n; i++){
			cin >> v[i].first;
			v[i].second = i+1;
		}
		sort(v.begin(), v.end());
		cout << countInversions(v) << endl;
	}
	return 0;
}