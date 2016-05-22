#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
#define maxn 110

vector<string> graph; int n;
bool visited[maxn][maxn];

#define isValid(x,y) (x>=0 && x<n && y>=0 && y<n) 

void getUnvisitedNeighbours(pii x, vector<pii>& next){
	int j=1,i=1;
	while(isValid(x.first, x.second+j) && graph[x.first][x.second+j]=='.')
		next.pb(mp(x.first, x.second+j)), j++;
	j=-1;
	while(isValid(x.first, x.second+j) && graph[x.first][x.second+j]=='.')
		next.pb(mp(x.first, x.second+j)), j--;
	while(isValid(x.first+i, x.second) && graph[x.first+i][x.second]=='.')
		next.pb(mp(x.first+i, x.second)), i++;
	i=-1;
	while(isValid(x.first+i, x.second) && graph[x.first+i][x.second]=='.')
		next.pb(mp(x.first+i, x.second)), i--;
}

int bfs(pii src, pii dest){
	if(src == dest)
		return 0;
	queue<pii> q; q.push(src); 
	visited[src.first][src.second] = true;
	int level = 0; bool flag = false;
	while(!q.empty()){
		queue<pii> qtemp;
		while(!q.empty()){
			pii curr = q.front(); q.pop();
			vector<pii> next; getUnvisitedNeighbours(curr, next);
			// cout << "Neighbours of " << curr.first << "," << curr.second << " are : ";
			for(int i=0; i<next.size(); i++){
				if(visited[next[i].first][next[i].second])
					continue;
				// cout << next[i].first <<"," << next[i].second << " ";
				visited[next[i].first][next[i].second] = true;
				qtemp.push(next[i]);
			}
			// cout << endl;
		}
		// cout << endl;
		q = qtemp; level++;
		if(visited[dest.first][dest.second]){
			flag = true;
			break;
		}
	}
	if(!flag)
		level = -1;
	return level;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n; graph.resize(n);
	for(int i=0; i<n; i++)
		cin >> graph[i];
	pii src, dest;
	cin >> src.first >> src.second >> dest.first >> dest.second;
	cout << bfs(src, dest) << endl;
	return 0;
}