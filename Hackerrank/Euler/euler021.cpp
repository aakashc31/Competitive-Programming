#include <bits/stdc++.h>

#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0; i<n; i++)

using namespace std;

typedef long long int lli;

bitset<100001> isAmicable;
lli ar[100001];

lli pow(lli a, lli p)
{
	if(p==0)
		return 1;
	int half = pow(a,p/2);
	half*=half;
	if(p&1)
		return half*a;
	return half;
}
lli sumOfProperDivisors(lli n)
{
	lli copy = n;
	lli num = 1;
	for(lli i=2;i*i<=n;i++)
	{
		lli temp=0;
		if(n%i==0)
		{
			while(n%i==0)
			{
				n/=i;
				temp++;
			}
			num *= ((pow(i,temp+1)-1)/(i-1));
		}
	}
	if(n>1)
		num*= (n+1);
	return num-copy;
}

void init()
{
	for(lli i=2; i<=100000; i++)
	{
		ar[i] = sumOfProperDivisors(i);
	}

	for(lli i=220; i<=100000; i++)
	{
		if(isAmicable[i])
			continue;
		if(ar[i]<=100000 && ar[ar[i]]==i && i!=ar[i])
			isAmicable[i] = isAmicable[ar[i]] = 1;
	}

	lli s=0;
	for(lli i=1; i<=100000; i++)
	{
		if(isAmicable[i])
			s+=i;
		ar[i] = s;
	}

}

int main()
{
	init();
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%lld\n",ar[n]);
	}
	return 0;
}