#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(lli i=0; i<n; i++)
#define get(n) scanf("%lld",&n)

typedef long long int lli;

lli fact(lli n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

int main()
{
	lli t,n;
	get(t);
	while(t--)
	{
		get(n);
		lli ar[13];
		f(i,13)
		{
			ar[i] = (n-1)/fact(12-i);
			printf("%d %d\n",ar[i],n);
			n = 1+(n%fact(12-i));
		}
	}
}