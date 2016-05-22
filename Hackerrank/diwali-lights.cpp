#include <stdio.h>
#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

const int modulo = 100000;
typedef long long int lli;
// returns 2^b mod modulo
int powermod(int b)
{
	if(b==0)
		return 1;
	if(b==1)
		return 2;
	if(b%2==0)
	{
		lli a = lli(powermod(b/2));
		a*=a;
		int r = a%modulo;
		return r;
	}
	else
	{
		lli a = lli(powermod(b/2));
		a = 2*a*a;
		int r = a%modulo;
		return r;
	}
}



int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		getNum(n);
		printf("%d\n",powermod(n)-1);
	}
	return 0;
}