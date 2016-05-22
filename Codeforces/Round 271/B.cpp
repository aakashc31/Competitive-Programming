#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
int ar[100000];

int main()
{
	int n,q,r,t;
	g(n);
	int s=0;
	f(i,n)
	{
		g(r);
		s+=r;
		ar[i] = s;
	}
	g(q);
	f(i,q)
	{
		g(r);
		t = lower_bound(ar,ar+n,r)-ar;
		printf("%d\n",t+1);
	}
	return 0;
}