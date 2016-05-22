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

const int inf = 1e9;

void dijkstra(int src, vvpii& graph){
	int n = graph.size();
	vi d(n, inf);
	vector<bool> mark(n, false);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	d[src] = 0; pq.push(mp(d[src],src));
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		if(mark[curr.second])
			continue;
		mark[curr.second] = true;
		for(pii& next : graph[curr.second]){
			int nCost = (next.second >= d[curr.second]) ? next.second : d[curr.second];
			if(nCost < d[next.first]){
				d[next.first] = nCost;
				pq.push(mp(nCost, next.first));
			}
		}
	}
	if(d[n-1] == inf)
		cout << "NO PATH EXISTS" << endl;
	else
		cout << d[n-1] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int n, e; cin >> n >> e;
	vvpii graph(n,vpii(0));
	int x,y,z;
	for(int i=0; i<e; i++){
		cin >> x >> y >> z;
		graph[x-1].pb(mp(y-1,z));
		graph[y-1].pb(mp(x-1,z));
	}
	dijkstra(0, graph);
	return 0;
}