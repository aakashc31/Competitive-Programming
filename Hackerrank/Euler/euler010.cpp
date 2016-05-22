#include <iostream>
#include <time.h>
#include <math.h>
#include <bitset>
#include <cstdio>
using namespace std;
typedef long long int lli;
#define getNum(n) scanf("%d",&n)
bitset<1000001> isPrime;
void getPrimesTill(int max)
{
	isPrime.flip();
	isPrime[0] = isPrime[1] = 0;
	for(int j = 2; j<=max; j++)
	{
		if(!isPrime[j])
			continue;
		long long int k = ((long long int)(j))*j;
		for( ; k<=max; k+=j)
		{
			isPrime[k] = 0;
		}		
	}
}
lli ans[1000000];
void in()
{
	ans[0] = 0;
	for(int i=2; i<=1000000; i++)
	{
		ans[i-1] = ans[i-2];
		if(isPrime[i])
			ans[i-1]+=i;
	}
}
int main()
{
	getPrimesTill(1000001);
	in();
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%lld\n",ans[n-1]);
	} 
	return 0;
}