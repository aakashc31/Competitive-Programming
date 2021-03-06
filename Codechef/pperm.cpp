#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)
int inputInteger()
{
	char ch = inpch;
	register int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = (r<<1) + (r<<3) + ch-'0';
		ch = inpch;
	}
	return r;
}

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
		long long int k = ((long long int)(j))*j;
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

int ar[5000001];
int main()
{
	int modulo = 1000000007;
	int m = 5000000;
	getPrimesTill(m);
	
	int p_ind = 0;
	int offset = 0;
	for(int i=1; i<=5000000; i++)
	{
		if(i==primes[p_ind])
			offset++, p_ind++;
		ar[i] = offset;
	}
	ar[1] = 1;
	for(int i=2;i<=5000000;i++)
	{
		long long int temp = ((long long int)(ar[i-1]))*(1+ar[i]);
		temp = temp%modulo;
		ar[i] = temp;
	}
	int t,n;
	t = inputInteger();
	while(t--)
	{
		n = inputInteger();
		printf("%d\n",ar[n]);
	}
	return 0;
}

/*How can I make it fast? 
 1. Store all the input integers in an array. Find max, then create the sieve only till max*/