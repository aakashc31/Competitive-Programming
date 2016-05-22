#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
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
	int n; cin >> n;
	vector<pair<string,string> > v(n);
	for(int i=0; i<n; i++){
		cin >> v[i].first;
		v[i].second = v[i].first; reverse(v[i].second.begin(), v[i].second.end());
	}
	sort(v.begin(), v.end());
	vector<pair<string, int> > s(n);
	for(int i=0; i<n; i++){
		s[i] = mp(v[i].second, i+1);
	}
	sort(s.begin(), s.end());
	vector<int> fin(n);
	for(int i=0; i<n; i++)
		fin[i] = s[i].second;
	cout << countInversions(fin) << endl;
	return 0;
}