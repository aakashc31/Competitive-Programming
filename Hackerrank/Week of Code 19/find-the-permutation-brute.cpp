#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair


int computeDistance(const vi& v){
	int ret = abs(v[1] - v[0]);
	for(int i=2; i<v.size(); i++){
		ret = min(ret, abs(v[i] - v[i-1]));
		if(ret < (v.size()/2))
			return 0;
	}
	if(ret == v.size()/2){
		for(int i=0; i<v.size(); i++)
			cout << v[i] << " ";
		cout << "ret = " << ret << endl;
	}
	return ret;
}

int main(){
	int n; cin >> n;
	vi v(n);
	for(int i=0; i<n; i++) 
		v[i] = i+1;
	int ans = computeDistance(v);
	while(next_permutation(v.begin(), v.end())){
		ans = max(ans, computeDistance(v));
	}
	cout << ans << endl;
	return 0;

}