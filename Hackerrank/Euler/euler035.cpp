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

int getNextRotation(int n)
{
	return (n%10)*ceil(pow(10,int(log(n)/log(10)))) + n/10;
}

bool isCircularPrime(int n)
{
	int cpy = n;
	while(true)
	{
		if(!isPrime[cpy])
			return false;
		cpy = getNextRotation(cpy);
		if(cpy == n)
			break;
	}
	return true;
}

int main()
{
	getPrimesTill(1000000);
	int n,s=0;
	g(n);
	f(i,n)
		s += isCircularPrime(i)?i:0;
	printf("%d\n",s);
	return 0;
}
