#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)
const lli modulo = 1000000007;

lli ar[10000];

int main()
{
	lli n,temp;
	g(n);
	f(i,n) g(ar[i]);
	for(int i=0; i<n-1; i++)
	{
		temp = (ar[i] + ar[i+1] + ar[i]*ar[i+1])%modulo;
		ar[i+1] = temp;
	}
	printf("%lld\n",ar[n-1]);
	return 0;
}