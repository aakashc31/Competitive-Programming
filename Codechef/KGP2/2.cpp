#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<char,char> pcc;

pcc ar[1000];
char S[1005], T[1005];

int table[256][256];
char a1,a2;

bool isReachable(char s, char t)
{
	int src = s;
	int dest = t;

	queue<int> q;
	q.push(src);
	bool visited[256];
	memset(visited, 0, sizeof visited);
	visited[src] = true;
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		f(i,256)
		{
			if(table[c][i]==1 && visited[i]!=true)
			{
				visited[i] = true;
				q.push(i);
			}
		}
		if(visited[dest])
			return true;
	}
	if(visited[dest])
			return true;
	return false;
}

int main()
{
	int p,m;
	g(p);
	while(p--)
	{
		scanf("%s",S);
		scanf("%s",T);
		g(m);
		f(i,256)
		{
			f(j,256)
				table[i][j] = 0;
		}

		f(i,m)
		{
			char temp[10];
			scanf("%s",temp);
			a1 = temp[0];
			a2 = temp[3];
			table[a1][a2] = 1;
		}
		bool flag = true;
		f(i,strlen(S))
		{
			if(S[i]!=T[i])
			{
				if(!isReachable(S[i], T[i]))
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}