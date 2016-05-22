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
	lli ar[41041];
	for(lli i=1;i<=41040;i++)
	{
		ar[i] = numDiv(triangle(i));
	}
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		for(lli i=1;i<=41040;i++)
		{
			if(ar[i]>n)
			{
				printf("%lld\n",triangle(i));
				break;
			}
		}
	}
	return 0;
}