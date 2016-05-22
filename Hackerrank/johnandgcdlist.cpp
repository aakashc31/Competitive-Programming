#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

int a[1000];
int lcm(int a, int b)
{
	return (a*b)/(__gcd(a,b));
}
int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(a[i]);
		printf("%d ",a[0]);
		f(i,n-1)
		{
			printf("%d ", lcm(a[i],a[i+1]));
		}
		printf("%d\n", a[n-1]);
	}
	return 0;
}