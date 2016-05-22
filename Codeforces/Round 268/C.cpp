#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
void simple(int n)
{
	printf("YES\n");
	printf("2 * 3 = 6\n");
	printf("6 - 1 = 5\n");
	printf("5 - 5 = 0\n");
	for(int j = 7; j<=n; j++)
		printf("%d * 0 = 0\n",j);
	printf("6 + 0 = 6\n");
	printf("6 * 4 = 24\n");
}
int main()
{
	int n;g(n);
	if(n>=6)
		simple(n);
	else
	{
		if(n==1 || n==2 || n==3)
			printf("NO\n");
		else if(n==4)
		{
			printf("YES\n");
			printf("4 * 3  = 12\n");
			printf("1 * 2 = 2\n");
			printf("12 * 2 =24\n");
		}
		else if(n==5)
		{
			printf("YES\n");
			printf("2 - 1 = 1\n");
			printf("5 * 4 = 20\n");
			printf("3 + 1 = 4\n");
			printf("20 + 4 = 24\n");
		}
	}
	return 0;
}