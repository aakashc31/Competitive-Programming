#include <bits/stdc++.h>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	int a1,b1,c,t,a,b;
	getNum(t);
	while(t--)
	{
		getNum(a1),getNum(b1),getNum(c);
		a=max(a1,b1);
		b=min(a1,b1);
		if(c>a)
		{
			printf("NO\n");
			continue;
		}
		int g = __gcd(a,b);
		// printf("%d\n",g );
		if(c%g==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
	
}