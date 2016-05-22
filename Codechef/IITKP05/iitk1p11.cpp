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
		g(n);
		if(n==1 || n==10 || n==100 || n==1000 || n==10000 || n==100000)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}