#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
typedef pair<int,int> pii;

pii lasers[16];
int ar[50][50];
int main()
{
	char ch[51];
	int t,n,m;
	g(t);
	int l;
	while(t--)
	{
		l=0; //num of lasers
		g(n),g(m);
		f(i,n)
		{
			scanf("%s",ch);
			f(j,m)
			{
				if(ch[j]=='.')
					ar[i][j]=0;
				else if(ch[j]=='E')
					ar[i][j]=-1;
				else
				{
					ar[i][j]=1;
					lasers[l++] = pii(i,j);
				}
			}
		}
		// input over
		bool flag = true;
		f(i,n)
		{
			f(j,m)
			{
				if(ar[i][j]==-1)
				{
					bool canBeKilled = false;
					f(k,l)
					{
						int li = lasers[k].first, lj = lasers[k].second;
						if(li==i || (lj==j && li>=i))
						{
							canBeKilled = true;
							break;
						}
					}
					if(!canBeKilled)
					{
						flag = false;
						printf("Impossible\n");
						break;
					}
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			printf("Possible\n");
	}
	return 0;
}