#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef pair<ll,ll> 	pll;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;



bool cmp(const pll& a, const pll& b){
	return a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	ll n,b,k, x1, x2; cin >> n >> x1 >> x2;
	vector<pll> v;
	f(i,n){
		cin >> k >> b;
		v.pb(mp(b + x2*k, b + x1*k));
	}
	sort(v.begin(), v.end());
	if(is_sorted(v.begin(), v.end(), cmp)){
		cout << "NO" << endl;
	}
	else{
		f(i,n){
			swap(v[i].first, v[i].second);
		}
		sort(v.begin(), v.end());
		if(is_sorted(v.begin(), v.end(), cmp)){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
	return 0;
}