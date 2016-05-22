#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)


int main()
{
	int t,n,m,a,s;
	g(t);
	while(t--)
	{
		s=0;
		g(n),g(m);
		f(i,n){
			g(a);
			s+=a;
		}
		if((m+s)%n==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}