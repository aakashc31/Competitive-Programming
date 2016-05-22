#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
int main()
{
	int n;
	g(n);
	int ans = 0,temp;
	f(i,n)
	{
		g(temp);
		ans = ans^temp;
	}
	printf("%d\n",ans);
	return 0;
}