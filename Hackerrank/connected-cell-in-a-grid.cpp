#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

set<pii> S;
int n,m; 
int ar[15][15];

#define isValid(x) (x.first >= 0 && x.first < m && x.second >= 0 && x.second < n)

int bfs(pii root){
	queue<pii> q; q.push(root); ar[root.first][root.second] = 0;
	int ret = 0;
	while(!q.empty()){
		pii curr = q.front(); q.pop();
		ret++;
		S.erase(S.find(curr));
		for(int i=-1; i<=1; i++){
			for(int j=-1; j<=1; j++){
				if(i==0 && j==0) continue;
				pii next = mp(curr.first + i, curr.second + j);
				if(!isValid(next)) continue;
				if(ar[next.first][next.second] == 0) continue;
				ar[next.first][next.second] = 0;
				q.push(next);
			}
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin >> ar[i][j];
			if(ar[i][j] == 1){
				S.insert(mp(i,j));
			}
		}
	}
	if(S.empty())
		cout << 0 << endl;
	else{
		int ans = 1;
		while(!S.empty()){
			pii curr = *(S.begin());
			ans = max(ans, bfs(curr));
		}
		cout << ans << endl;
	}
	return 0;
}