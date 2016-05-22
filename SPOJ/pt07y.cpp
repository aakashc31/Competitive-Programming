// connected graph with n-1 edges is a tree

#include <vector>
#include <stdio.h>
#include <bitset>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long int lli;
typedef vector< vector<int> > vvi;
typedef vector<int> vi;

bitset<10000> isReached;
int tree[10000][10000];
int index[10000];

void dfs(int i)
{
	if(isReached[i])
		return;
	isReached[i] = 1;
	f(j,index[i])
	{
		if(tree[i][j]!=-1)
		dfs(tree[i][j]);
	}
}

int main()
{
	f(i,10000)
	{
		f(j,10000)
		{
			tree[i][j]=-1;
		}
		index[i]=0;
	}
	int n,m;
	int a,b;
	getNum(n);
	getNum(m);
	f(i,m)
	{
		getNum(a),getNum(b);
		tree[a-1][index[a-1]] = (b-1);
		tree[b-1][index[b-1]] = (a-1);
		index[a-1]++;
		index[b-1]++;
	}
	// input over
	if(m!=n-1)
	{
		printf("NO\n");
		return 0;
	}
	dfs(0);
	bool flag = true;
	f(i,n)
	{
		if(!isReached[i])
		{
			flag = false;
			break;
		}
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}