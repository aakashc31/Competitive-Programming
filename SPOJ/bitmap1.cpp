#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
const int maxint = INT_MAX;
char ch[185][185];
int ar[185][185];
int main()
{
	int t, n, m;
	g(t);
	while(t--)
	{
		g(n), g(m);
		f(i,n) scanf("%s",ch[i]);
		queue<pii> q;
		f(i,n)
		{
			f(j,m)
			{
				if(ch[i][j]=='1')
				{
					q.push(make_pair(i,j));
					ar[i][j] = 0;
				}
				else
					ar[i][j] = maxint;
			}
		}

		while(!q.empty())
		{
			pii p = q.front();
			q.pop();
			int x = p.first, y = p.second;
			// 
			for(int i=-1; i<=1; i++)
			{
				for(int j=-1; j<=1; j++)
				{
					if(i==j || i==-j)
						continue;
					int nx = x+i, ny = y+j;
					if(nx>=0 && nx<n && ny>=0 && ny<m)
					{
						if(1+ar[x][y] < ar[nx][ny])
						{
							ar[nx][ny] = 1+ar[x][y];
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
		f(i,n)
		{
			f(j,m)
				printf("%d ",ar[i][j]);
			printf("\n");
		}
	}
	return 0;
}