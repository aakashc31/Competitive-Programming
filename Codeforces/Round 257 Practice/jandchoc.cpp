#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

lli area(int n, int m, int x, int y)
{
	return (lli(floor(double(n)/x))*(lli(floor(double(m)/y))));
}

int main()
{
	int n,m,k;
	getNum(n), getNum(m), getNum(k);
	if(n>m)
		swap(n,m);
	// now n<=m
	lli final;
	if(k <= n-1)
	{
		final = max(area(n,m,1,k+1), area(n,m,k+1,1));
	}
	else if( k<=m-1)
	{
		final = area(n,m,1,k+1);
	}
	else if(k<= n+m-2)
	{
		final = area(n,m,k+2-m,m);
	}
	else
	{
		final = -1;
	}
	printf("%lld\n",final);
	return 0;
}