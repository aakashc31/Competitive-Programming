#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
// #define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int n,m;
int graph[100][100];

//(size of subtree, number of edges broken)
pii getCount(int root, bool* visited)
{
	visited[root] = true;
	pii ret = mp(1,0);
	for(int i=0; i<n; i++)
	{
		if(graph[root][i] != -1 && (!visited[i]))
		{
			pii childCount = getCount(i, visited);
			ret.first += childCount.first;
			ret.second += childCount.second;
			ret.second += ((childCount.first % 2 == 0) ? 1 : 0);
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			graph[i][j] = -1;

	for(int i=0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	bool *visited = new bool[n];
	memset(visited, 0, n);
	pii ans = getCount(0, visited);
	cout << ans.second << endl;
	return 0;
}