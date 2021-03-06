#include <iostream>
#include <stdio.h>
#include <cmath>
#include <bitset>
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



int ar[5000001];
int main()
{
	int modulo = 1000000007,max=0,tint,t;
	t = inputInteger();
	int inpar[t]; 

	//input from user
	f(i,t)
	{
		tint = inputInteger();
		inpar[i] = tint;
		if(tint > max)
			max = tint;
	}
	//
	bitset<5000001> isPrime;
	// int numPrimes = 0;
	isPrime.flip();
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		// numPrimes++;
		long long int k = ((long long int)(j))*j;
		for( ; k<=max; k+=j)
		{

			isPrime[k] = 0;
		}		
	}
	//
	int offset = 0;
	ar[1] = 1;
	for(int i=2; i<=max; i++)
	{
		if(isPrime[i])
			offset++;
		long long int temp = ((long long int)(ar[i-1]))*(1+offset);
		temp = temp%modulo;
		ar[i] = temp;
	}
	
	
	f(i,t)
		printf("%d\n",ar[inpar[i]]);
	return 0;
}

/*How can I make it fast? 
 1. Store all the input integers in an array. Find max, then create the sieve only till max
 2. don't create the array of primes?*/