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

ll countInversions(vector<int>& v){
	BIT* b = new BIT(v.size());
	ll ans = 0;
	for(int& x : v){
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
		vector<string> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		map<string,int> m; string st;
		for(int i=0; i<n; i++){
			cin >> st;
			m[st] = i+1;
		}
		vector<int> ar(n);
		for(int i=0; i<n; i++){
			ar[i] = (m.find(v[i]))->second;
		}
		cout << countInversions(ar) << endl;
	}
	return 0;
}