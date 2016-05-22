#include <bits/stdc++.h>
using namespace std;
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

bitset<10000> isReached;
vvi graph(10000,vi(1,0));
int num=0;
void dfs(int i)
{
	isReached[i] = 1;
	num++;
	for(int j=1; j<=graph[i][0];j++)
	{
		int next = graph[i][j];
		if(!isReached[next])
		{
			dfs(next);
		}
	}
}

int main()
{
	int m,n;
	getNum(n), getNum(m);
	f(i,m)
	{
		int a,b;
		getNum(a),getNum(b);
		a--,b--;
		graph[a].push_back(b);
		graph[a][0]++;
		graph[b].push_back(a);
		graph[b][0]++;
	}
	if(m==n-1)
	{
		dfs(0);
		if(num==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("NO\n");
	return 0;
}

