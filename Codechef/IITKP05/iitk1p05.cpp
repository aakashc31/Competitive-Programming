#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)

int main()
{
	int t,n,ans,temp;
	g(t);
	while(t--)
	{
		ans=0;
		g(n);
		f(i,n)
		{
			g(temp);
			if(temp>ans)
				ans = temp;
		} 
		printf("%d\n",ans);
	}
	return 0;
}