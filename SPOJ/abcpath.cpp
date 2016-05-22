#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int maxn = 55;
int m,n; //m is row, n is column
string graph[maxn];
vector<pii> allRoots;
bool visited[maxn][maxn];

#define isValid(x) (x.first >= 0 && x.first < m && x.second >= 0 && x.second < n)

int findPathLen(pii root){
	int level = 1; pii dummy = mp(-1,-1);
	memset(visited, 0, sizeof visited);
	queue<pii> q; q.push(root); q.push(dummy); visited[root.first][root.second] = true;
	while(!q.empty()){
		pii curr = q.front(); q.pop();
		if(curr == dummy){
			if(!q.empty()){
				level++;
				q.push(dummy);
			}
			continue;
		}
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(i==0 && j==0)
					continue;
				pii next = mp(curr.first + i, curr.second + j);
				if(isValid(next) && !visited[next.first][next.second] && graph[next.first][next.second] == graph[curr.first][curr.second] + 1){
					visited[next.first][next.second] = true;
					q.push(next);
				}
			}
		}
	}
	return level;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n; int t = 1;
	while(m!=0 || n!=0){
		allRoots.clear();
		for(int i=0; i<m; i++){
			cin >> graph[i];
			for(int j=0; j<n; j++){
				if(graph[i][j] == 'A')
					allRoots.pb(mp(i,j));
			}
		}
		int ans = 0;
		for(vector<pii>::iterator it = allRoots.begin(); it != allRoots.end(); it++){
			ans = max(ans, findPathLen(*it));
			if(ans == 26) break;
		}
		cout << "Case " << t << ": " << ans << endl;
		cin >> m >> n;
		t++;
	}
	return 0;
}
