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
typedef pair<int, int> pii;

const int inf = 1000000;

vvi out_graph(100000,vi(1,0)); //for every vertex a, stores those b, s.t. a->b. and out_graph[a][0] = no. of outgoing edges

vvi in_graph(100000,vi(1,0)); // for every vertex a, stores those b, s.t. a<-b. and out_graph[a][0] = no. of incoming edges



bitset<100000> is_visited; //visits a vertex if it's min_rev is calculated.

int rev_min=inf;

int dp[100000];

// path is path till now, nr is the 
void bfs()
{
	queue<int> q;
	q.push(0);
	dp[0]=0;
	while(!q.empty())
	{
		int v = q.front();
		int k = dp[v]; //num rev to reach from 0 to v
		q.pop();
		for(int i=1;i<=out_graph[v][0];i++)
		{
			int neighbour = out_graph[v][i];
			if(dp[neighbour] > k)
			{
				dp[neighbour] = k;
				q.push(neighbour);
			}
		}

		for(int i=1;i<=in_graph[v][0];i++)
		{
			int neighbour = in_graph[v][i];
			if(dp[neighbour] > k+1)
			{
				dp[neighbour] = k+1;
				q.push(neighbour);
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
		if(a==b)
			continue;
		out_graph[a-1].push_back(b-1);
		out_graph[a-1][0]++;
		
		in_graph[b-1].push_back(a-1);
		in_graph[b-1][0]++;
	}
	f(i,n) dp[i]=inf;
	bfs();
	if(dp[n-1]==inf)
		printf("-1\n");
	else
		printf("%d\n",dp[n-1]);
	return 0;	
}