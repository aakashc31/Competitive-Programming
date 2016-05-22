#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define mp make_pair

int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		if((n&1) || (n<6) || (n==10))
			printf("RIDICULOUS\n");
		else if(n==6 || n==12 || n==18)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}