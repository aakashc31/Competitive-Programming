#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

const int inf = 1e9;

int dijkstra(int src, int dest, vvpii& graph){
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
		if(curr.second == dest)
			break;
		for(pii& next : graph[curr.second]){
			int nCost = curr.first + next.second;
			if(nCost < d[next.first]){
				d[next.first] = nCost;
				pq.push(mp(nCost, next.first));
			}
		}
	}
	return (d[dest] == inf) ? -1 : d[dest];
}

int main(){
	ios::sync_with_stdio(false);
	int t,n, nr, cost, p, r, src, dest; cin >> t; string st,source, destination;
	while(t--){
		cin >> n; vvpii graph(n, vpii(0));
		map<string,int> m;
		for(int i=0; i<n; i++){
			cin >> st;
			m[st] = i;
			cin >> p;
			while(p--){
				cin >> nr >> cost;
				graph[i].pb(mp(nr-1,cost));
				// graph[nr-1].pb(mp(i, cost));
			}
		}
		cin >> r;
		while(r--){
			cin >> source >> destination;
			src = m.find(source)->second;
			dest = m.find(destination)->second;
			cout << dijkstra(src, dest, graph) << endl;
		}
	}
}