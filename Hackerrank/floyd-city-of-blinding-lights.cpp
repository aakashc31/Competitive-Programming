#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef unsigned long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;
const int inf = 1e9; const int maxn = 410;
int dist[maxn][maxn];
int n,m;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m; int x,y,r,q;
	fill(dist[0], dist[0] + maxn*maxn, inf);
	for(int i=0; i<m; i++){
		cin >> x >> y >> r;
		x--, y--; dist[x][y] = r;
	}
	for(int i=0; i<n; i++)
		dist[i][i] = 0;
	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k]+dist[k][j];
			}
		}
	}
	cin >> q;
	while(q--){
		cin >> x >> y; int ans = dist[x-1][y-1]; if(ans == inf) ans = -1;
		cout << ans << endl; 
	}
	return 0;
}