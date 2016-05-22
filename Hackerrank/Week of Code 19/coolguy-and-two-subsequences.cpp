#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

const int modulo = 1e9 + 7;

inline ll nc2(ll x){
	ll r = (x*(x-1))/2;
	return r % modulo;
}

inline ll nc3(ll x){
	ll r = (x*(x-1)*(x-2))/6;
	return r%modulo;
}


int main(){
	int n; cin >> n;
	vector<pii> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i].first; v[i].second = i;
	}
	sort(v.begin(), v.end());
	ll S = nc2(n+1), p, L, R, ans = 0;
	set<int> nums; set<int>::iterator it;
	for(int i=0; i<n; i++){
		p = v[i].second;
		if(nums.empty()){
			L = 0; R = n-1;
		}
		else{
			if(p < (*nums.begin())){
				// cout << "xxx   " << *nums.begin() << " ";
				L = 0;
			}
			else{
				it = nums.lower_bound(p); it--;
				L = (*it) + 1;
			}
			it = nums.end(); it--;
			if(p > *it){
				// cout << "yyy   " << *it << " zzz ";
				R = n-1;
			}
			else
				R = (*nums.upper_bound(p))-1;
		}
		// cout << v[i].first << " p = " << p <<" L = " << L << " R = " << R << endl; 
		ll term = (S - nc2(R-L+2) + modulo) % modulo;
		term = (term * (R-p+1)) % modulo; term = (term * (p - L + 1)) % modulo;
		ll term2 = (R-p+1)*(nc3(p-L+2)) % modulo;
		ll term3 = (p-L+1)*(nc3(R-p+2)) % modulo;
		term = (term + term2 + term3) % modulo;
		term = (term * v[i].first) % modulo;
		ans = (ans + term) % modulo;
		S = (S - nc2(R-L+2) + modulo + nc2(p-L+1) + nc2(R-p+1)) % modulo;
		nums.insert(p);
	}
	cout << ans << endl;
	return 0;
}