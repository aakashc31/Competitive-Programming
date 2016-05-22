#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,bool> plb;

#define HORIZONTAL 	false
#define VERTICAL	true

const int mod = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	ll t,m,n,x; cin >> t;
	while(t--){
		cin >> m >> n;
		priority_queue<plb, vector<plb>, less<plb> > pq;
		for(int i=0; i<m-1; i++){
			cin >> x;
			pq.push(mp(x, VERTICAL));
		}
		for(int i=0; i<n-1; i++){
			cin >> x;
			pq.push(mp(x, HORIZONTAL));
		}
		ll hCount = 0, vCount = 0;
		ll ans = 0;
		while(!pq.empty()){
			plb curr = pq.top(); pq.pop();
			if(curr.second == VERTICAL){
				ans += (curr.first * (hCount+1));
				ans %= mod;
				vCount++;
			}
			else{
				ans += (curr.first * (vCount + 1));
				ans %= mod;
				hCount++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}