#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)

int main()
{
	int n,k,m,a[4];
	g(n),g(k);
	cin >> m;
	f(i,n)
	{
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		f(i,4)
		{
			for(int j=i+1; j<4; j++)
			{
				printf("g = %d\n",__gcd(a[i],a[j]));
			}
		}
	}
	return 0;
}