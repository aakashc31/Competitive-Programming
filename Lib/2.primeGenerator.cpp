#include <iostream>
#include <time.h>
#include <math.h>

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
void printPrimes()
{
	for(int i=0;i<numPrimes;i++)
	{
		cout<<primes[i]<<endl;
	}
}
void printPrimesBetween(int a, int b)
{
	//int root = sqrt(b);
	
	//printPrimes();
	for(int k = a; k<=b ; k++)
	{
		int flag = 1;
		int sq = sqrt(k);
		for(int i = 0; i<numPrimes ; i++)
		{

			if((k%primes[i]==0 && k!=primes[i]))
			{
				flag = 0;
				break;
			}

			if(primes[i]>sq)
				break;

		}
		if(flag == 1 && k!=1)
			cout<<k<<endl;
	}
}

int main()
{
	int root = sqrt(1000000000);
	getPrimesTill(root);
	int testcases = 0;
	cin>>testcases;
	int tt = testcases;
	int* input = new int[2*testcases];
	int ind = 0;
	int ub,lb;
	while(testcases>0)
	{
		

		cin>>lb;
		cin>>ub;
		input[ind] = lb;
		input[ind+1] = ub;
		ind+=2;
		//printPrimesBetween(lb,ub);

		//cout<<endl;
		testcases--;
	}
	time_t t1;
	time(&t1);
	for(int j=0; j<tt; j+=1)
	{
		printPrimesBetween(input[2*j],input[2*j+1]);
		cout<<endl;
	}
	time_t t2;
	time(&t2);
	//cout<<t2-t1<<endl;
	return 0;
}