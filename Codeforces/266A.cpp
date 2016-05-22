#include <bits/stdc++.h>
typedef long long int lli;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0 ;i<n; i++)
using namespace std;

int main()
{
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	if((m*a) <= b)
		printf("%d\n",n*a);
	else
	{
		int q = n/m, r = n%m;
		printf("%d\n",q*b+ min(r*a,b));
	}
	return 0;
}