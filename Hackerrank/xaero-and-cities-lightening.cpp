#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

int isLighted[500000];
int dp[500000][2];
bool isVisited[500000];
vi graph[500000];

void dfs(int root){
	isVisited[root] = true;
	int g0 = 0, g1 = 0; 
	for(int i=0; i<graph[root].size(); i++){
		int next = graph[root][i];
		if(!isVisited[next]){
			dfs(next);
			g0 += dp[next][1];
			g1 += min(dp[next][0], dp[next][1]);
		}
	}
	if(!isLighted[root])
		g1++;
	else
		g0 = (1<<29);
	dp[root][0] = g0;
	dp[root][1] = g1;
}

int main(){
	int t,n,u,v;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++){
			graph[i].clear();
			cin >> isLighted[i];
			dp[i][0] = dp[i][1] = 0;
		}
		for(int i=0; i<n-1; i++){
			cin >> u >> v;
			u--,v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(isVisited,0,n);
		dfs(0);
		cout << min(dp[0][0], dp[0][1]) << endl;
	}
	return 0;
}