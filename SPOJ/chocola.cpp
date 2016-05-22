#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,bool> pib;

#define HORIZONTAL 	false
#define VERTICAL	true

int main(){
	ios::sync_with_stdio(false);
	int t,m,n,x; cin >> t;
	while(t--){
		cin >> m >> n;
		priority_queue<pib, vector<pib>, less<pib> > pq;
		for(int i=0; i<m-1; i++){
			cin >> x;
			pq.push(mp(x, VERTICAL));
		}
		for(int i=0; i<n-1; i++){
			cin >> x;
			pq.push(mp(x, HORIZONTAL));
		}
		int hCount = 0, vCount = 0;
		ll ans = 0;
		while(!pq.empty()){
			pib curr = pq.top(); pq.pop();
			if(curr.second == VERTICAL){
				ans += (curr.first * (hCount+1));
				vCount++;
			}
			else{
				ans += (curr.first * (vCount + 1));
				hCount++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}