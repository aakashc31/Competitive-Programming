#include <cstdio>

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
#define MAXINT 1000000;
struct pair
{
	int x,y;
};

char ch[200][200];
pair white[40000];
int dist[200][200];
int l;

int abs(int a)
{
	if(a<0)
		return -a;
	else
		return a;
}

int bfs(int i, int j)
{
	
}

int main()
{
	int t,n,m;
	getNum(t);
	while(t--)
	{
		l=0;
		getNum(n), getNum(m);
		f(i,n)
		{
			scanf("%s",ch[i]);
			f(j,m)
			{
				if(ch[i][j]=='1')
					{white[l].x = i; white[l].y = j; l++; dist[i][j] = 0;}
				else
					dist[i][j] = MAXINT;
			}
		}
		// 
		f(i,n)
		{
			f(j,m)
			{
				if(dist[i][j] != 0)
					dist[i][j] = getMinDist(i,j);
				printf("%d ",dist[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}