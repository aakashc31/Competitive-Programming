#include <stdio.h>
#define getNum(n) scanf("%lld",&n)
int main()
{
	long long int a,b,s;
	getNum(a);getNum(b);
	s=a+b;
	printf("%lld\n",s);
	return 0;
}