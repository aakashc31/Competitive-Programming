#include <iostream>
#include <time.h>
#include <math.h>
#include <bitset>
#include <cstdio>
using namespace std;

#define getNum(n) scanf("%d",&n)
int *primes;
int numPrimes;
void getPrimesTill(int max)
{
	
	bool* isPrime = new bool[max+1];
	numPrimes = 0;
	for(int j=0; j<=max;j++)
		isPrime[j] = true;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		// unsigned long k = j*j;
		long long int k = ((long long int)(j))*j; //updated on 3/7/2014 7:25 p.m.
		for( ; k<=max; k+=j)
		{

			isPrime[k] = false;
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

int main()
{
	getPrimesTill(110000);
	// printf("%d\n",numPrimes);
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%d\n",primes[n-1]);
	}
	return 0;
}