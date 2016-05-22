// machau...

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;
const int modulo = 1000000007;
const int size = 100001;

int ar[size];
lli fact[size];
lli ifact[size];

void init_fact();
void inti_ifact();
lli inverse_mod(lli i);
lli power_mod(lli i, int p);
lli ncr_mod(lli n, lli r);

int main()
{
	init_fact();
	inti_ifact();
	int n,k;
	getNum(n), getNum(k);
	f(i,n)
		getNum(ar[i+1]);
	// input over
	sort(ar+1,ar+n+1);
	// array has been sorted.
	lli a = 0, b=0;
	for(int i=1; i<=n-k+1; i++)
	{
		lli t = ncr_mod(n-i,k-1);
		b = (b+ ar[i]*t)%modulo;
		a = (a+ ar[n-i+1]*t)%modulo;
	}
	lli s = (a + modulo - 1 - (b-1)%modulo)%modulo;
	printf("%lld\n",s);
	return 0;
}

void init_fact()
{
	fact[0] = 1;
	for(lli i=1;i<size;i++)
	{
		fact[i] = (fact[i-1]*i)%modulo;
	}
}


void inti_ifact()
{
	ifact[0] = 1;
	ifact[1] = 1;
	for(lli i=2; i<size; i++)
	{
		ifact[i] = (ifact[i-1]*inverse_mod(i))%modulo;
	}
}

lli inverse_mod(lli i)
{
	return power_mod(i,modulo-2);
}

// compute i^p % modulo
lli power_mod(lli i, int p)
{
	if(p==0)
		return 1;
	else if(p%2==0)
	{
		lli half = power_mod(i,p/2);
		half = (half*half)%modulo;
		return half;
	}
	else
	{
		lli half = power_mod(i,p/2);
		half = (((half*half)%modulo)*i)%modulo;
		return half;
	}

}

lli ncr_mod(lli n, lli r)
{
	lli p = ((fact[n]*ifact[r])%modulo)*ifact[n-r];
	return p%modulo;
}
