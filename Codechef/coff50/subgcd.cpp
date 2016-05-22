#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

int ar[100000];

int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		int q = __gcd(ar[0],ar[1]);
		for(int i=2;i<n;i++)
			q = __gcd(ar[i],q);
		if(q==1)
			printf("%d\n",n);
		else
			printf("-1\n"); 
	}
	return 0;
}