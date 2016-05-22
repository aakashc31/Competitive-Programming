#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
// int ar[100000];
int n,t,temp;

int *primes;
int numPrimes;
void getPrimes()
{
	int max = 1000000;
	bitset<1000001> isPrime;
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	numPrimes = 0;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		long long int k = ((long long int)(j))*j; //updated on 3/7/2014 7:25 p.m.
		for( ; k<=max; k+=j)
			isPrime[k] = 0;
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

int mycount[1000001];
void compute(int a)
{
	f(i,numPrimes)
	{
		int &p = primes[i];
		// printf("Prime = %d\n",p);
		if(p*p > a)
			break;
		if(a%p==0)
		{
			// printf("Found factor of %d - %d\n",a,p);
			int tt = 0;
			while(a%p==0)
			{
				tt++;
				a/=p;
			}
			if(tt> mycount[p])
				mycount[p]=tt;
		}
	}
	if(a>1 && mycount[a]==0) mycount[a]=1;
}
int main()
{
	getPrimes();
	g(t);
	while(t--)
	{
		g(n);
		memset(mycount,0,sizeof mycount);
		f(i,n) 
		{
			g(temp);
			compute(temp);
		}
		int ans=0;
		f(i,1000001) ans+=mycount[i];
		printf("%d\n", ans);
		
	}
	return 0;
}