#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)

int getNth(int x, int y, int n)
{
	n = n%6;
	if(n==1)
		return x;
	if(n==2)
		return y;
	if(n==3)
		return y-x;
	if(n==4)
		return -1*x;
	if(n==5)
		return -1*y;
	return x-y;
}

int main()
{
	int x,y,n;
	getNum(x),getNum(y), getNum(n);
	int nth = getNth(x,y,n);
	// printf("%d\n",nth);
	long long int modulo = 1000000007;
	if(nth >= 0)
	{
		printf("%d\n", nth%1000000007);
	}
	else
	{
		modulo = ((modulo-1)*((-nth)%modulo))%modulo;
		printf("%lld\n",modulo);
	}
	return 0;
}