#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

int main(){
	ios::sync_with_stdio(false);
	int n,k; cin >> n >> k; ll x,y;
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for(int i=0; i<n; i++){
		cin >> x; pq.push(x);
	}
	int ret = 0; bool flag = true;
	while(pq.top() < k){
		if(pq.size() == 1){
			flag = false;
			break;
		}
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();
		pq.push(x + 2*y);
		ret++;
	}
	if(flag)
		cout << ret << endl;
	else
		cout << -1 << endl;
	return 0;
}