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

int isCat[100005];
int visited[100005];
int numCats[100005];
int maxEndingHere[100005];

int main(){
	int n,m,x,y;
	cin >> n >> m;
	vvi graph(n,vi(0));
	for(int i=0; i<n; i++)
		cin >> isCat[i];
	for(int i=0; i<n-1;i++){
		cin >> x >> y;
		x--;y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	queue<int> q;
	q.push(0);
	numCats[0] = isCat[0];
	maxEndingHere[0] = isCat[0];
	int ans = 0;
	while(!q.empty()){
		int root = q.front();
		q.pop();
		visited[root] = 1;
		bool isLeaf = true;
		for(int i=0; i<graph[root].size(); i++){
			int child = graph[root][i];
			if(!visited[child]){
				maxEndingHere[child] = (isCat[child] == 1) ? maxEndingHere[root] + 1 : 0;
				numCats[child] = max(numCats[root], maxEndingHere[child]);
				q.push(child);
				isLeaf = false;
			}
		}
		if(isLeaf){
			if(numCats[root] <= m)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}