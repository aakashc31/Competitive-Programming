#include <stdio.h>
#define getNum(n) scanf("%d",&n)
typedef long long int lli;
lli sum(int n)
{
	lli t = n;
	lli m = (t*(t+1))/2;
	return m;
}

int main()
{
	int t,n;
    getNum(t);
	while(t--)
	{
		getNum(n);
		n--;
		int num3,num5,num15;
		num3 = n/3;
		num5 = n/5;
		num15 = n/15;
		lli s = (3*sum(num3)) + (5*sum(num5)) -(15*sum(num15));
		printf("%lld\n",s);
	}
	return  0;
}