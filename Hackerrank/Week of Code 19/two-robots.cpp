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
unordered_map<int,int> M;
int n;
vector<pii> q;


int dp(int i, int x1, int x2){
	int h = i*maxn*maxn + maxn*x1 + x2;
	unordered_map<int,int>::iterator it = M.find(h);
	if(it != M.end()){
		// cout << "yo" << endl;
		return it->second;
	}
	int cost1 = abs(q[i].second - q[i].first) + ((x1 == 0) ?  0 : abs(q[i].first - x1));
	int cost2 = abs(q[i].second - q[i].first) + ((x2 == 0) ?  0 : abs(q[i].first - x2));
	if(i == n-1){
		M[h] = min(cost1, cost2);
		return min(cost1, cost2);
	}
	int ans = min(cost2 + dp(i+1, x1, q[i].second), cost1 + dp(i+1, q[i].second, x2));
	M[h] = ans;
	return ans;
}

int main(){
	// ios::sync_with_stdio(false);
	int t,m; scanf("%d",&t);
	while(t--){
		M.clear();
		scanf("%d",&m);scanf("%d",&n);
		q.resize(n);
		for(int i=0; i<n; i++){
			scanf("%d",&q[i].first);scanf("%d",&q[i].second);
		}
		printf("%d\n", dp(0,0,0));
	}
	return 0;
}