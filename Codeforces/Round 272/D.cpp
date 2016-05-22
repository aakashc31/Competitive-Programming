#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)

int main()
{
	int n,k;
	g(n),g(k);
	printf("%d\n",(6*(n-1)+5)*k);
	for(int i=0; i<n; i++)
	{
		printf("%d %d %d %d\n",(6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k);
	}
	return 0;
}