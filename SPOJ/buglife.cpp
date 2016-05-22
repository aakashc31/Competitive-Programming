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

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}


int gender[2000];
set<int> S;

bool dfs(int root, vvi& graph, int currGender){
	gender[root] = currGender;
	S.erase(root);
	bool ret;
	for(int i=0; i<graph[root].size(); i++){
		int next = graph[root][i];
		if(gender[next] == -1){ //unvisited
			ret = dfs(next, graph, 1 - currGender);
			if(!ret)
				return false;
		}
		else if(gender[next] + gender[root] != 1)
			return false;
	}
	return true;
}

int main(){
	int T,n,m,x,y;
	T = inp();
	for(int t=1; t<=T; t++){
		n = inp();
		m = inp();
		vvi graph(n, vi(0));
		memset(gender, 0xff, 4*n);
		for(int i=0; i<m; i++){
			x = inp();
			y = inp();
			x--, y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		printf("Scenario #%d:\n",t);
		bool ans = true;
		S.clear();
		for(int i=0; i<n; i++)
			S.insert(i);
		while(!S.empty()){
			set<int>::iterator it = S.lower_bound(0);
			if(it == S.end())
				break;
			int nextUnvisited = *it;
			ans = dfs(nextUnvisited, graph, 0);
			if(!ans)
				break;
		}
		if(ans)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}