#include <bits/stdc++.h>

using namespace std;

#define getcx getchar//_unlocked
#define f(i,n) for(int i=0; i<n; i++)

inline void get( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

typedef vector<int> vi;
typedef vector< vector<int> > vvi;

vvi directed_graph(100000,vi(1,0));
vvi undir_graph(100000,vi(1,0));
vi parent(100000,-1);
bitset<100000> is_visited;

void bfs(int n)
{
	is_visited.set();
	is_visited.flip();

	queue<int> q;
	q.push(0);

	is_visited[0]=1;

	while(!q.empty())
	{
		int i = q.front();
		q.pop();
		for(int j=1; j<=undir_graph[i][0]; j++)
		{
			int neigh = undir_graph[i][j];
			if(!is_visited[neigh])
			{
				is_visited[neigh]=1;
				parent[neigh]=i;
				// printf("parent[%d] = %d\n",neigh+1,i+1);
				q.push(neigh);
				if(neigh==n-1)
					return;
			}
		}
	}
}

int main()
{
	int n,m;
	get(n),get(m);
	f(i,m)
	{
		int a,b;
		get(a), get(b);
		directed_graph[a-1].push_back(b-1);
		directed_graph[a-1][0]++;
		undir_graph[a-1].push_back(b-1);
		undir_graph[a-1][0]++;
		undir_graph[b-1].push_back(a-1);
		undir_graph[b-1][0]++;
	}

	// we need a path from 0 to n-1
	// f(i,n)
	// {
	// 	for(int j=1; j<=graph[i][0]; j++)
	// 	{
	// 		printf("%d -> %d\n",i+1,graph[i][j]+1);
	// 	}
	// }
	bfs(n);
	if(!is_visited[n-1])
		printf("-1\n");
	else
	{
		int k=n-1;
		int s=0;
		while(parent[k]!=-1)
		{
			// if there is no directed edge from parent[k] to k, s++
			int p=parent[k];
			bool flag = false;
			for(int j=1;j<=directed_graph[p][0];j++)
			{
				if(directed_graph[p][j]==k)
				{
					flag = true;
					break;
				}
			}
			if(!flag)
				s++;
			k=parent[k];
		}
		printf("%d\n",s);
	}
	return 0;
	
}