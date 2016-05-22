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
vvi graph;
int h[maxn], r[maxn], par[maxn];
int SQRT;
void dfs(int v, int p = -1){
	h[v] = (p == -1) ? 0 : h[p]+1;
	par[v] = p;
	if(h[v] % SQRT == 0)
		r[v] = p;
	else
		r[v] = r[p];
	for(int i=0; i<graph[v].size(); i++){
		if(graph[v][i] != p)
			dfs(graph[v][i], v);
	}
}

int query(int v, int u){
	if(v == u)
		return v;
	if(h[v] < h[u])
		swap(u,v);
	if(h[v] == h[u])
		return (r[v] == r[u]) ? query(par[v], par[u]) : query(r[v], r[u]);
	if(h[v] - h[u] < SQRT)
		return query(par[v], u);
	return query(r[v], u);
}

int main(){
	int T = inp(),n,m,q,x,y, root;
	vector<bool> isRoot;
	for(int t=0; t<T; t++){
		graph.clear();
		n = inp(); graph.resize(n); isRoot.resize(n,true);
		SQRT = ceil(sqrt(n));
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