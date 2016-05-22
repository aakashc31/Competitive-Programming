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

char S[1005], T[1005];

int table[26][26];
char a1,a2;

bool isReachable(char s, char t)
{
	int src = s-'a';
	int dest = t-'a';

	queue<int> q;
	q.push(src);
	bool visited[26];
	memset(visited, 0, sizeof visited);
	visited[src] = true;
	while(!q.empty())
	{
		int c = q.front();
		q.pop();
		f(i,26)
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
		f(i,26)
		{
			f(j,26)
				table[i][j] = 0;
		}

		f(i,m)
		{
			char temp[10];
			scanf("%s",temp);
			a1 = temp[0];
			a2 = temp[3];
			table[a1-'a'][a2-'a'] = 1;
		}
		if(strlen(S)!= strlen(T))
		{
			printf("NO\n");
			continue;
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