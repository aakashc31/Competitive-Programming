#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0; i<n; i++)
#define MAX 1000000

typedef long long int lli;

lli s[MAX];
lli c[MAX];
int main()
{
	lli n;
	getNum(n);
	f(i,n)
		getNum(s[i]);
	f(i,n)
		getNum(c[i]);
	sort(s,s+n);
	sort(c,c+n);
	lli pdt_sum = 0;
	f(i,n)
	{
		lli temp = c[i]*s[i];
		pdt_sum+=temp;
	}
	printf("%lld\n", pdt_sum);
	return 0;
}	