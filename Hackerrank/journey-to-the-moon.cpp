#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vector<pii> > vvpii;

vvi graph;
vector<bool> visited;
set<int> unvisited;

int dfs(int root){
	// cout << "dfs " << root << endl; 
	set<int>::iterator it = unvisited.find(root);
	if(it != unvisited.end())
		unvisited.erase(it);
	visited[root] = true;
	int ans = 1;
	for(int& next : graph[root]){
		if(visited[next])
			continue;
		ans += dfs(next);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int n,e,x,y; cin >> n >> e;
	graph.resize(n); visited.resize(n, false);
	for(int i=0; i<e; i++){
		cin >> x >> y;
		graph[x].pb(y); graph[y].pb(x);
	}
	for(int i=0; i<n; i++)
		unvisited.insert(i);
	vector<ll> ans(0); vector<ll> pref(0);
	while(!unvisited.empty()){
		ans.pb(dfs(*unvisited.begin()));
		int i = ans.size()-1;
		if(i==0) pref.pb(ans[0]);
		else pref.pb(pref[i-1]+ans[i]);
	}
	ll ret = 0;
	for(int i=ans.size()-1; i>0; i--){
		ret += (ans[i] * pref[i-1]);
	}
	cout << ret << endl;
	return 0;
}