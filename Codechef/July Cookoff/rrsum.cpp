#include <cstdio>
#include <bitset>
using namespace std;

#define f(i,n) for(lli i=0; i<n; i++)
#define getNum(n) scanf("%lld",&n)
typedef long long int lli;

lli query(lli k, lli n)
{
	if(k<2 || k>2*n)
		return 0;
	if(k<=n+1)
		return k-1;
	else
		return (2*n-k+1);
}
int main()
{
	lli n,m,q;
	getNum(n);
	getNum(m);
	while(m--)
	{
		getNum(q);
		printf("%lld\n",query(q-n,n));
	}
	return 0;
}