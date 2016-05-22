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

// (max dist between two nodes in the subtree, depth of the subtree)
pii dfs(int index, bool* visited, vvi& graph){
	visited[index] = true;
	bool isLeaf = true;
	for(int i=0; i<graph[index].size(); i++){
		if(!visited[graph[index][i]]){
			isLeaf = false;
			break;
		}
	}

	if(isLeaf){
		return mp(0, 1);
	}
	pii ret = mp(-1,-1);
	int next;
	pii curr;
	int bestDepth = -1, secondBest = -1;
	for(int i=0; i<graph[index].size(); i++){
		next = graph[index][i];
		if(!visited[next]){
			curr = dfs(next, visited, graph);
			ret.first = max(ret.first, curr.first);
			ret.second = max(ret.second, curr.second+1);
			if(curr.second > bestDepth){
				secondBest = bestDepth;
				bestDepth = curr.second;
			}
			else if(curr.second > secondBest){
				secondBest = curr.second;
			}

		}
	}

	ret.first = max(ret.first, ret.second-1);
	if((bestDepth != -1) && (secondBest != -1))
		ret.first = max(ret.first, bestDepth + secondBest);
	return ret;
}


int main(){
	int n,x,y;
	cin >> n;
	vvi graph(n, vi(0));
	bool* visited = new bool[n];
	memset(visited, 0, n);
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		x--,y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cout << dfs(0, visited, graph).first << endl;
	return 0;
}