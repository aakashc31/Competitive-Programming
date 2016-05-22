//TLE, see prpalin_u.cpp
#include <iostream>
#include <stdio.h>
using namespace std;
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

int reverse(int n)
{
	int rev = 0;
	while(n>0)
	{
		int d = n%10;
		rev = rev*10 + d;
		n/=10;
	}
	return rev;
}
bool isPalindrome(int n)
{
	return (reverse(n)==n);
}
int main()
{
	int n;
	std::cin >> n;
	getPrimesTill(10000000);
	for(int i=0; i<numPrimes; i++)
	{
		if(isPalindrome(primes[i]))
		{
			cout << primes[i] << ",";
			// break;
		}
	}
	return 0;
}