#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
bitset<1000001> isPrime;
void getPrimesTill(int max)
{
	isPrime.set();
	int numPrimes = 0;
	isPrime[0] = isPrime[1] = 0;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		long long int k = ((long long int)(j))*j; //updated on 3/7/2014 7:25 p.m.
		for( ; k<=max; k+=j)
		{

			isPrime[k] = 0;
		}		
	}
}

// tested
int getLeftTrunc(int n)
{
	int ndig = int(log(n)/log(10)) + 1;
	if(ndig==1)
		return -1;
	int fd = n/ceil(pow(10,ndig-1));
	return n - fd*ceil(pow(10,ndig-1));
}

bool isTruncPrime(int n)
{
	int c = n;
	// checking right trunc
	while(n>0)
	{
		if(!isPrime[n])
			return false;
		n/=10;
	}
	n=c;
	while(n!=-1)
	{
		if(!isPrime[n])
			return false;
		n = getLeftTrunc(n);
	}
	return true;
}

int main()
{
	getPrimesTill(1000000);
	int n,s=0;
	g(n);
	for(int i=10; i<n;i++)
		s+= isTruncPrime(i) ? i:0;
	printf("%d\n",s);
	return 0;
}