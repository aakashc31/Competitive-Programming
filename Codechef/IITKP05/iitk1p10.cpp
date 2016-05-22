#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef long long int lli;
bitset<100000> visited;
lli ar[100000];
int parent[100000];
int mycount[100000];
vvi graph(100000,vi(0));

int get(int i, int par)
{
	if(mycount[i]!=-1)
		return mycount[i];
	parent[i] = par;
	visited[i]=1;
	int s=ar[i]?0:1;
	f(j,graph[i].size())
	{
		int next = graph[i][j];
		if(visited[next]==0)
		{
			s+=get(next,i);
		}
	}
	mycount[i]=s;
	// printf("count %d = %d\n",i,s);
	return s;
}

int main()
{
	int n,qt;
	int a,b,x,v;
	g(n),g(qt);
	
	f(i,n) mycount[i]=-1;
	f(i,n-1)
	{
		g(a),g(b);
		a--,b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	f(i,n) g(ar[i]);
	visited.set(); visited.flip();
	get(0,0);
	f(i,qt)
	{
		char ch;
		cin>>ch;
		cin>>x;
		if(ch=='U')
		{
			g(v);
			x--;
			if(v==0)
				continue;
			int oldv = ar[x];
			int newv = oldv+v;
			ar[x] = newv;
			if(newv==0)
			{
				int par = x;
				while(par!=parent[par])
				{
					mycount[par]++;
					par = parent[par];
				}
				mycount[par]++;
			}
			else if(oldv==0)
			{
				int par = x;
				while(par!=parent[par])
				{
					mycount[par]--;
					par = parent[par];
				}
				mycount[par]--;
			}
		}
		else
		{
			// g(x);
			// printf("%d\n",x);
			x--;
			printf("%d\n",mycount[x]);
		}
	}
	return 0;
}