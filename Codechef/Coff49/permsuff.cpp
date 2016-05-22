#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
typedef pair<int,int> pii;
int ar[100000];
pii prs[100000];
bool comparator(const pii& a, const pii& b)
{
	return (a.first <= b.first && a.second <= b.second);
}

bool isPermut(int i, int j)
{
	bool f = true;
	for(int k=i;k<=j;k++)
	{
		if(ar[k]>=i&&ar[k]<=j)
		{

		}
		else
		{
			f=false;
			break;
		}
	}
	return f;
}

int main()
{
	int t,n,m,x,y;
	g(t);
	while(t--)
	{
		g(n),g(m);
		f(i,n) {g(ar[i]);ar[i]--;}
		f(i,m)
		{
			g(x),g(y);x--,y--;
			prs[i].first=x, prs[i].second=y;
		}
		sort(prs,prs+m,comparator);
		bool flag = true;
		int beg = prs[0].first;
		
		// from 0 to beg-1
		f(i,beg)
		{
			if(ar[i]!=i)
			{
				flag=false;
				break;
			}
		}
		int end;
		f(i,m-1)
		{
			if(prs[i].second<prs[i+1].first)
			{
				if(!isPermut(beg,prs[i].second))
				{
					flag = false;
					break;
				}
				for(int j=prs[i].second+1;j<prs[i+1].first;j++)
				{
					if(ar[j]!=j)
					{
						flag=false;
						// printf("2 break\n");
						break;
					}
				}
				beg = prs[i+1].first;
			}
		}
		if(!isPermut(beg,prs[m-1].second))
			flag=false;
		for(int j=prs[m-1].second+1;j<n;j++)
		{
			if(ar[j]!=j)
			{
				flag = false;
				// printf("4 break - %d, %d, %d\n",ar[j],j,n-1 );
				break;
			}
		}
		if(flag==false)
			printf("Impossible");
		else
			printf("Possible");
		// if(t!=0)
			printf("\n");
		
	}
	return 0;
}