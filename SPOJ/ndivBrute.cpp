#include <bits/stdc++.h>

typedef long long int lli;

#define f(i,n) for(int i=0; i<n; i++)
#define getStr(st) scanf("%s",st)
#define getNum(n) scanf("%lld",&n)

lli numDivisors(lli n)
{
	if(n==1)
		return 1;
	lli ret = 1;
	lli copy = n;
	for(lli i = 2; i*i <= n; i++)
	{
		lli temp = 0;
		while(n%i==0)
		{
			n/=i;
			temp++;
		}
		ret*=(1+temp);
	}
	if(n==copy)
		return 2;
	else if(n==1)
		return ret;
	else
		return (2*ret);
}

int main()
{
	lli a,b,n;
	getNum(a), getNum(b), getNum(n);
	lli s = 0;
	for(lli i=a; i<=b; i++)
	{
		if(numDivisors(i)==n)
			s++;
	}
	printf("%lld\n",s);
	return 0;
}