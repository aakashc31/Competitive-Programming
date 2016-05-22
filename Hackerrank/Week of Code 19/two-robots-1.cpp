#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
const int maxn = 1000;
vector<pii> q;
int n;

int compute(){
	int ans = abs(q[0].first - q[0].second);
	int h1 = q[0].second, h2 = 0;
	for(int i=1; i<n; i++){
		ans += abs(q[i].first - q[i].second);
		if(abs(h1 - q[i].first) == 0){
			h1 = q[i].second;
		}
		else if(h2 == 0){
			h2 = q[i].second;
		}
		else{
			if(abs(h1 - q[i].first) <= abs(h2 - q[i].first)){
				ans += abs(h1 - q[i].first);
				h1 = q[i].second;
			}
			else{
				ans += abs(h2 - q[i].first);
				h2 = q[i].second;
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t,m; cin >> t;
	while(t--){
		cin >> m >> n;
		q.resize(n);
		for(int i=0; i<n; i++)
			cin >> q[i].first >> q[i].second;
		cout << compute() << endl;
	}
	return 0;
}