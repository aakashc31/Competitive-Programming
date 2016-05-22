#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define gt(n) scanf("%d",&n)


int getmax(int a, int b, int c)
{
	return max(a,max(b,c));
}

int main()
{
	int t,r,g,b,m;
	int R,G,B,temp;
	gt(t);
	while(t--)
	{
		gt(r),gt(g),gt(b),gt(m);
		gt(R);
		f(i,r-1){
			gt(temp);
			if(temp > R) R = temp;
		}
		gt(G);
		f(i,g-1)
		{
			gt(temp);
			if(temp > G) G = temp;
		}
		gt(B);
		f(i,b-1)
		{
			gt(temp);
			if(temp > B) B = temp;
		}
		int ans = getmax(R,G,B);
		f(i,m)
		{
			if(R >= G)
			{
				if(R >= B)
				{
					R/=2;
					// B++,G++;
				}
				else
				{
					B/=2;
					// R++,G++;
				}
			}
			else
			{
				if(G>=B)
				{
					G/=2;
					// R++,B++;
				}
				else
				{
					B/=2;
					// R++,G++;
				}
			}

			if(getmax(R,G,B) < ans)
				ans = getmax(R,G,B);
		}
		printf("%d\n",ans);
	}
	return 0;
}