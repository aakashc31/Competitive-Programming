#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

int fun(int n)
{
	int s = 0;
	f(i,n)
	{
		int k = i+1;
		s+= (k*k*k*k*(n/k));
	}
	return s;
}

int main()
{
	int n=1;
	while(n<10)
	{
		// g(n);
		printf("f(%d) = %d\n",n,fun(n));
		n++;
	}
	return 0;
}