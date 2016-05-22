// TLE.. lediv.cpp is correct
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
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
		unsigned long k = j*j;
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
	int t;
	getNum(t);
	getPrimesTill(100000);
	while(t--)
	{
		int n;
		getNum(n);
		int ar[n];
		int min = 100001;
		f(i,n)
		{
			getNum(ar[i]);
			if(ar[i] < min)
				min = ar[i];
		}
		if(min == 1)
		{
			printf("-1\n");
			continue;
		}
		int sq = sqrt(min);
		int primeDiv[2*sq+1];
		int numDiv = 0;
		int i=0;
		while(primes[i]<=min && i<numPrimes)
		{
			if(min%primes[i]==0)
				primeDiv[numDiv++] = primes[i];
			i++;
		}
		// cout << "numDiv = "<<numDiv <<endl;
		bool flag = false;
		f(j,numDiv)
		{
			bool allDiv = true;
			f(k,n)
			{
				if(ar[k]%primeDiv[j]!=0)
				{
					allDiv = false;
					break;
				}
			}
			if(allDiv)
			{
				printf("%d\n",primeDiv[j]);
				flag = true;
				break;
			}
		}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}