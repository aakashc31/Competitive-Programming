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


vector<string> graph;
int r,c;
int dp[1000][1000];

inline bool isValid(pii p){
	return (p.first >= 0 && p.first < r && p.second >=0 && p.second < c);
}


inline pii getRoot(){
	f(i,r){
		f(j,c){
			if(graph[i][j] == '.')
				return mp(i,j);
		}
	}
	return mp(-1,-1);
}

void getChild(pii curr, vector<pii>& next){
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if((i==0) ^ (j==0)){
				//either i == 0 or j == 0, not both
				if(isValid(mp(curr.first + i, curr.second + j))){
					if((dp[curr.first+i][curr.second+j] == -1) && graph[curr.first+i][curr.second+j] == '.')
						next.pb(mp(curr.first+i, curr.second+j));
				}
			}
		}
	}
}

inline pii getNodeByDepth(int depth){
	f(i,r){
		f(j,c){
			if(dp[i][j] == depth)
				return mp(i,j);
		}
	}
	cout << "Not found!" << endl;
	return mp(-1,-1);
}

int bfs(pii root){
	f(i,r){
		f(j,c)
			dp[i][j] = -1;
	}

	queue<pii> q;
	q.push(root);
	dp[root.first][root.second] = 0;
	
	pii temp;
	vector<pii> unvisited_children;

	q.push(mp(-1,-1)); //dummy node
	int currDepth = 1;

	while(!q.empty()){
		pii curr = q.front();
		q.pop();
		if(curr.first < 0){
			if(!q.empty()){
				q.push(mp(-1,-1));
				currDepth++;
			}
			continue;
		}

		unvisited_children.clear();
		getChild(curr, unvisited_children);
		f(i, unvisited_children.size()){
			temp = unvisited_children[i];
			dp[temp.first][temp.second] = currDepth;
			q.push(temp);
		}
	}

	return currDepth-1;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> c >> r;
		graph.resize(r);
		f(i,r)  cin >> graph[i];
		// cout << "root = " << getRoot().first << " " << getRoot().second << endl;
		int mDepth = bfs(getRoot());
		// cout << "Max depth node = " << getNodeByDepth(mDepth).first << " " << getNodeByDepth(mDepth).second << endl;
		cout << "Maximum rope length is " << bfs(getNodeByDepth(mDepth)) << "." << endl;
	}
	return 0;
}