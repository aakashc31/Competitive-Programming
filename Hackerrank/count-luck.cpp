#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int n,m,k;
string ar[100];
vector<vector<pii> > par;
vvi child;

#define isValid(x) (x.first >= 0 && x.first < n && x.second >= 0 && x.second < m)

void dfs(pii root){
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(!((i==0) ^ (j==0))) continue;
			pii next = mp(root.first + i, root.second + j);
			if((!isValid(next)) || (ar[next.first][next.second] == 'X')) continue;
			ar[next.first][next.second] = 'X';
			par[next.first][next.second] = root;
			child[root.first][root.second]++;
			dfs(next);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=0; i<n; i++)
			cin >> ar[i];
		cin >> k;
		pii src=mp(-1,-1), dest=mp(-1,-1);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(ar[i][j] == 'M')
					src = mp(i,j);
				else if(ar[i][j] == '*')
					dest = mp(i,j);
			}
		}
		par = vector<vector<pii> >(n, vector<pii>(m, mp(-1,-1)));
		child = vvi(n, vi(m,0));
		ar[src.first][src.second] = 'X';
		dfs(src);
		int waves = 0;
		pii p = par[dest.first][dest.second];
		while(p != mp(-1,-1)){
			if(child[p.first][p.second] > 1)
				waves++;
			p = par[p.first][p.second];
		}
		if(waves == k)
			cout << "Impressed" << endl;
		else
			cout << "Oops!" << endl;
	}
	return 0;
}