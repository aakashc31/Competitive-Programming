#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
typedef long long int lli;


int main()
{
	int t,n,k;
	g(t);
	while(t--)
	{
		g(n), g(k);
		if(n==1 && k==1)
		{
			printf("1\n");
			continue;
		}
		int m = n/2;
		if(k > m)
			printf("-1\n");
		else
		{
			f(i,k)
				printf("%d ",2*i+2);
			printf("\n");
		}
	}
	return 0;
} 