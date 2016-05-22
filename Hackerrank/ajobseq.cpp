// time limit is exceeding. Why?
// O(p) inversion calculation. AC
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <ctime>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;
const int size = 100010;

lli modulo; //prime number input each time by the user

lli fact[size];
lli ifact[size];
lli inv[size];
void init_fact();
void inti_ifact();

// inverse mod calc is taking long time. Need to optimize this. there must be a way to find it quickly.
lli inverse_mod(lli i);
lli power_mod(lli i, int p);
lli ncr_mod_large(lli n, lli r);
lli ncr_mod(lli n, lli r);
void calculate_inverses();
int main()
{
	lli t,n,k,p;
	getLong(t);
	// t = 100;
	// time_t t1;
	// time(&t1);
	while(t--)
	{
		getLong(n), getLong(k), getLong(p);
		// n=3216516161321321, k= 656546465, p= 99991;
		modulo = p;
		calculate_inverses();
		init_fact();
		inti_ifact();
		
		printf("%lld\n",ncr_mod_large(n+1,k+1));
	}
	// time_t t2;
	// time(&t2);
	// cout << t2-t1 << endl;
	return 0;
}

void init_fact()
{
	fact[0] = 1;
	for(lli i=1;i<modulo;i++)
	{
		fact[i] = (fact[i-1]*i)%modulo;
	}
}


void inti_ifact()
{
	ifact[0] = 1;
	ifact[1] = 1;
	for(lli i=2; i<modulo; i++)
	{
		ifact[i] = (ifact[i-1]*inv[i])%modulo;
		
	}
}

void calculate_inverses()
{
	inv[1] = 1;
	lli p = modulo;
	for(lli i=2; i<p; i++)
	{
		inv[i] = ((p - p/i)*(inv[p%i]))%p;
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
		half = (half*half*i)%modulo;
		return half;
	}

}

lli ncr_mod(lli n, lli r)
{
	if(n<r)
		return 0;
	lli p = ((fact[n]*ifact[r])%modulo)*ifact[n-r];
	return p%modulo;
}

// here we'll have to use Lucas' theorem
lli ncr_mod_large(lli n1, lli r1)
{
	
	lli n[100];
	lli r[100];
	int nlen = 0, rlen = 0;
	while(n1>0)
	{
		n[nlen++] = n1%modulo;
		n1/=modulo;
	}
	while(r1>0)
	{
		r[rlen++] = r1%modulo;
		r1/=modulo;
	}
	if(nlen < rlen)
		return 0;
	lli p =1;
	// stored in base modulo
	for(int i=0; i<rlen;i++)
	{
		p*= ncr_mod(n[i],r[i]);
		p%=modulo; 
		if(p==0)
			return 0;
	}
	return p;

}