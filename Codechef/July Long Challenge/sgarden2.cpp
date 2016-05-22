#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
#define modulo 1000000007;


int *primes;
int numPrimes;
void getPrimesTill(int max)
{
	
	bitset<100001> isPrime;
	numPrimes = 0;
	isPrime.flip();
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		// unsigned long k = j*j;
		long long int k = ((long long int)(j))*j; //updated on 3/7/2014 7:25 p.m.
		for( ; k<=max; k+=j)
		{

			isPrime[k] = 0;
		}		
	}
	primes = new int[numPrimes];
	int index = 0;
	for(int l = 2; l<=max; l++)
	{
		if(isPrime[l])
			{
				primes[index] = l;
				index++;
			}

	}
}

int factors[100001];
int ar[100001];

void factorize(int n)
{
	int i=0,s=0,p;
	while(i<numPrimes)
	{
		p = primes[i];
		if(p>n)
			break;
		s=0;
		while(n%p==0)
			s++, n/=p;
		if(factors[p] < s)
			factors[p] = s;
		i++;
	}
}

int findlcm(int n)
{
	int ans = 1;
	for(int i=0;i<numPrimes;i++)
	{
		long long int p = pow(primes[i],factors[primes[i]]);
		p = (p%1000000007)*(ans);
		ans = (p%1000000007);
	}
	return ans;
}

int main()
{
	getPrimesTill(100000);
	int t,n;
	getNum(t);

	while(t--)
	{
		int g = 1;
		long long int ans = 1;
		bitset<100001> iscalc;
		// bitset<100001> chain_length;
		int u = 0, max=0;
		getNum(n);
		f(i,n)
		{
			getNum(ar[i+1]);
			factors[i+1] = 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(iscalc[i])
				continue;
			iscalc[i] = 1;
			int pr = ar[i];
			int t = 1;
			while(pr!=i)
			{
				iscalc[i] = 1;
				t++;
				pr = ar[pr];
			}
			// if(!chain_length[t])
			// {
			// 	chain_length[t]=1;
			// 	factorize(t);
			// }
			factorize(t);
		}
		
		printf("%d\n",findlcm(n));
	}
	return 0;

}
