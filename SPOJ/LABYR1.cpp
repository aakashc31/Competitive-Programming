#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

int n,m;

inline bool isValid(pii p){
	return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}

inline vector<pii> getNeighbours(pii p, vector<string>& graph){
	vector<pii> ret;
	pii c = p; c.first+=1;
	if(isValid(c)){
		if(graph[c.first][c.second] == '.')
			ret.pb(c);
	}
	
	c = p; c.first -= 1;
	if(isValid(c)){
		if(graph[c.first][c.second] == '.')
			ret.pb(c);
	}

	c = p; c.second += 1;
	if(isValid(c)){
		if(graph[c.first][c.second] == '.')
			ret.pb(c);
	}

	c = p; c.second -= 1;
	if(isValid(c)){
		if(graph[c.first][c.second] == '.')
			ret.pb(c);
	}

	return ret;
}

// (max dist between two nodes in the subtree, depth of the subtree)
pii dfs(pii index, bool** visited, vector<string>& graph){
	cout << "dfs(" << index.first << "," << index.second << ")" << endl;
	int i = index.first, j = index.second;
	if(!isValid(index))
		return mp(-1,-1);
	if(graph[i][j] != '.'){
		return mp(-1, -1);
	}

	visited[i][j] = true;
	vector<pii> next = getNeighbours(index, graph);

	bool isLeaf = true;
	f(i, next.size()){
		if(!visited[next[i].first][next[i].second]){
			isLeaf = false;
			break;
		}
	}

	if(isLeaf) return mp(0,1);

	pii ret = mp(-1,-1);
	pii curr, neigh;
	int bestDepth = -1, secondBest = -1;
	for(int i=0; i<next.size(); i++){
		neigh = next[i];
		if(!visited[neigh.first][neigh.second]){
			curr = dfs(neigh, visited, graph);
			ret.first = max(ret.first, curr.first);
			ret.second = max(ret.second, curr.second+1);
			if(curr.second > bestDepth){
				secondBest = bestDepth;
				bestDepth = curr.second;
			}
			else if(curr.second > secondBest){
				secondBest = curr.second;
			}

		}
	}

	ret.first = max(ret.first, ret.second-1);
	if((bestDepth != -1) && (secondBest != -1))
		ret.first = max(ret.first, bestDepth + secondBest);
	return ret;

}

int main(){
	std::ios::sync_with_stdio(false);
	int t;
	vector<string> graph;
	bool **visited;
	visited = new bool*[1000];
	f(i,1000){
		visited[i] = new bool[1000];
	}
	int r,c;
	cin >> t;
	while(t--){
		graph.clear();
		cin >> m >> n;
		graph.resize(n);
		f(i,n) {
			cin >> graph[i];
		}
		f(i,n){
			memset(visited[i], 0, m);
		}
		r = -1, c = -1;
		f(i,n){
			f(j,m){
				if(graph[i][j] == '.'){
					r = i, c = j;
					goto outer;
				}
			}
		}
		outer:
		if(r==-1){
			cout << "0" << endl;
			continue;	
		}
		cout << "r = " << r << " c = " << c << endl;
		cout << dfs(mp(r,c), visited, graph).first << endl;
	}
	return 0;
}