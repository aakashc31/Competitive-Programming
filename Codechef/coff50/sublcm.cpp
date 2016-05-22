#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n; i++)
#define g(n) scanf("%d",&n)

bitset<1000001> isPrime;
bitset<78500> visited;
int *primes;
int numPrimes;
void getPrimesTill(int max)
{
	
	numPrimes = 0;
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;

	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		numPrimes++;
		long long int k = ((long long int)(j))*j; 
		for( ; k<=max; k+=j)
		{
			isPrime[k] = 0;
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

int ar[100000];

void set_visited(int n)
{
	visited.set();
	visited.flip();
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
		{
			visited[i] = 1;
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		visited[n] = 1;
}

void set_visited_2(int n)
{
	visited.set();
	visited.flip();
	for(int i=0; i<numPrimes; i++)
	{
		if(n%primes[i]==0)
		{
			visited[primes[i]]=1;
			while(n%primes[i]==0)
				n/=primes[i];
		}
	}
}

int main()
{
	getPrimesTill(1000000);
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		int q = __gcd(ar[0],ar[1]);
		for(int i=2;i<n;i++)
			q = __gcd(ar[i],q);
		if(q>1)
		{
			printf("-1\n");
			continue;
		}
		int maxl = 1;
		int tot = 1;
		set_visited(ar[0]);
		for(int i=1; i<n; i++)
		{
			int temp = ar[i];
			bool flag = true;
			for(int j=2; j*j<=temp; j++)
			{
				if(temp%j==0)
				{
					if(visited[j])
					{
						flag = false;
						break;
					}
					else
					{
						visited[j] = 1;
						while(temp%j==0)
							temp/=j;
					}
				}
			}
			if(temp>1)
			{
				if(visited[temp])
				{
					flag = false;
				}
				else
					visited[temp] = 1;
			}

			if(flag)
			{
				maxl++;
				if(maxl > tot)
					tot = maxl;
			}
			else
			{
				maxl = 1;
				set_visited(ar[i]);
			}
		}
		if(tot==1)
			printf("-1\n");
		else
			printf("%d\n",tot);
	}
	return 0;
}