#include <stdio.h>
typedef long long int  lli;
#define getNum(n) scanf("%lld",&n)
int main()
{
	lli t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		if(n<=2)
			printf("-1\n");
		else
		{
			if(n%2==1)
				printf("2\n");
			else if(n%4==0)
				printf("3\n");
			else
				printf("4\n");
		}
	}
	return 0;
}