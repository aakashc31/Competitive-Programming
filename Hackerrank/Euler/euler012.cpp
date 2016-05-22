#include <iostream>
#include <cstdio>

#define f(i,n) for(lli i=0; i<n; i++)
#define getNum(n) scanf("%lld",&n)

typedef long long int lli;

lli numDiv(lli n)
{
	lli n_div = 1;
	for(lli i=2; i*i <= n; i++)
	{
		lli temp = 0;
		while(n%i==0)
		{
			temp++;
			n/=i;
		}
		n_div*=(1+temp);
	}
	if(n>1)
		n_div*=2;
	return n_div;
}

lli triangle(lli n)
{
	return (n*(n+1))/2;
}

int main()
{
	lli max = 41042;
	lli ar[1025];
	f(i,1025)
		ar[i]=-1;
	f(i,max)
	{
		lli temp = numDiv(triangle(i+1));
		if(ar[temp]==-1)
			ar[temp] = triangle(i+1);
	}
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		n++;
		// n+=2;
		if(ar[n]!=-1)
			printf("%lld\n",ar[n]);
		else
		{
			lli u = n;
			while(ar[u]==-1) u++;
			printf("%lld\n",ar[u]);
		}
	}
	return 0;
}