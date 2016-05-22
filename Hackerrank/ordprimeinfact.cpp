#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;

// power of p in n!
lli ord(lli n, lli p)
{
	lli s = 0;
	while(n>0)
	{
		s += (n/p);
		n/=p;
	}
	return s;
}

lli fgh(lli p, lli l)
{
	lli s = 0;
	f(i,l)
	{
		if(ord(i+1,p)%p==0)
			s++;
	}
	return s;
}

int main()
{
	lli t,p,l;
	getLong(t);
	while(t--)
	{
		getLong(p);
		getLong(l);
		printf("%lld\n",fgh(p,l));
	}
	return 0;
}