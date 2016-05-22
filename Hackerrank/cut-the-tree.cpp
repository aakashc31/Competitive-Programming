#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

vi weights;
vvi graph;
vi par; //par[i] denotes parent of i
vi wtSub;

int dfs(int root, int p = -1){
	par[root] = p; int ret = weights[root];
	for(int& next : graph[root]){
		if(next != p)
			ret += dfs(next, root);
	}
	wtSub[root] = ret;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	weights.resize(n); par = vi(n,-1); graph = vvi(n, vi(0)); wtSub.resize(n);
	for(int i=0; i<n; i++) cin >> weights[i];
	int x,y;
	for(int i=0; i<n-1;i++){
		cin >> x >> y;
		graph[x-1].pb(y-1);
		graph[y-1].pb(x-1);
	}
	int total = dfs(0);
	int ans = 1e9 + 7, curr;
	for(int i=1; i<n; i++){
		curr = abs(total - 2*wtSub[i]);
		ans = min(ans, curr);
	}
	cout << ans << endl;
	return 0;
}