// 
#include <iostream>
#include <stdio.h>
#include <cmath>
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

int compute(int n, int c)
{
	if(c==0)
		return 1;
	if(c%2==0)
	{
		int a = compute(n,c/2);
		int t = a*a;
		return (t)%10000;
	}
	else
	{
		int a = compute(n,c-1);
		int t = n*a; 
		return (t)%10000;
	}
}

int power(int n, int p) //power of p in n, p is a prime
{
	int s=0;
	while(n%p==0)
	{
		n/=p;
		s++;
	}
	return s;
}

int main()
{
	int t;
	getNum(t);
	getPrimesTill(500000);
	numPrimes--;
	while(t-- > 0)
	{
		int n;
		getNum(n);
		int divNum = 1; //this will store the number of divisors of the number n
		float num = 1.0;
		//finding the number of factors
		f(i,numPrimes)
		{
			if(n < primes[i])
				break;
			if(n%primes[i]==0)
			{
				int temp = power(n,primes[i]);
				divNum *= (1+temp);
				num *= pow(primes[i],temp);
				// cout << "num = "<<num <<endl;
				if(num==n)
				{
					// cout << "yy\n";
					break;
				}
			}
			// cout << "Yo "<<i<<endl;
		}
		divNum-=2; 
		int pdt = 0;
		if(divNum%2==0)
		{
			pdt = compute(n,divNum/2);
		}
		else
		{
			pdt = compute(n,divNum/2);
			int k = sqrt(n);
			pdt = (pdt*(k%10000))%10000;
		}
		float kk = (divNum/2)*(log10(n));
		kk = ceil(kk);
		bool flag = false;
		if(kk>=5.0)
			flag = true;
		if(!flag)
			printf("%d\n", pdt);
		else
		{
			if(pdt<10)
				printf("000%d\n",pdt );
			else if(pdt < 100)
				printf("00%d\n",pdt );
			else if(pdt < 1000)
				printf("0%d\n",pdt );
			else
				printf("%d\n",pdt );
		}
	}
	return 0;
}