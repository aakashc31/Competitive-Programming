#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

const int maxn = 1100;
const int maxlog = 11;

int h[maxn];
int par[maxn][maxlog];
vvi graph;

void dfs(int u, int p = -1){
	par[u][0] = p;
	h[u] = (p != -1) ? h[p] + 1 : 0;
	for(int i=1; i<maxlog; i++)
		par[u][i] = (par[u][i-1] != -1) ? par[par[u][i-1]][i-1] : -1;
	for(int i=0; i<graph[u].size(); i++)
		if(graph[u][i] != p)
			dfs(graph[u][i], u);
}

int query(int u, int v){
	if(h[v] < h[u])
		swap(u,v);
	for(int i=maxlog-1; i>=0; i--){
		if(par[v][i] != -1 && h[par[v][i]] >= h[u])
			v = par[v][i];
	}
	if(v == u)
		return v;
	for(int i=maxlog-1; i>=0; i--){
		if(par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	}
	return par[v][0];
}

int main(){
	int T = inp(),n,m,q,x,y, root;
	vector<bool> isRoot;
	for(int t=0; t<T; t++){
		graph.clear();
		n = inp(); graph.resize(n); isRoot.resize(n,true);
		for(int i=0; i<n; i++){
			m = inp(); graph[i].resize(m);
			for(int j=0; j<m; j++){
				graph[i][j] = inp()-1;
				isRoot[graph[i][j]] = false;
			}
		}
		root = 0;
		while(!isRoot[root])
			root;
		dfs(root);
		q = inp();
		printf("Case %d:\n", t+1);
		while(q--){
			x = inp()-1; y = inp()-1;
			printf("%d\n", query(x,y)+1);
		}
	}
	return 0;
}