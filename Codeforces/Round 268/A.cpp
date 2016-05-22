#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
bitset<100> v;
int main()
{
	v.set(); v.flip();
	int n,p,q,t,s=0;
	g(n);
	g(p);
	f(i,p)
	{
		g(t);
		if(!v[t-1])
		{
			v[t-1]=1;
			s++;
		}
	}
	g(p);
	f(i,p)
	{
		g(t);
		if(!v[t-1])
		{
			v[t-1]=1;
			s++;
		}
	}
	if(s==n)
		printf("I become the guy.\n");
	else
		printf("Oh, my keyboard!\n");
	return 0;
}