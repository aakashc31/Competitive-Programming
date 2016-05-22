#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)

int main()
{
	int n,m,k;
	g(n),g(m);
	k = m;
	if(m>n)
		printf("-1\n");
	else
	{
		while(true)
		{
			if(n <= 2*m)
			{
				printf("%d\n",m);
				break;
			}
			m+=k;
		}
	}
	return 0;
}