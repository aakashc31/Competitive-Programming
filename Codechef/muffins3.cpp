#include <iostream>
#include <stdio.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define gN(n) scanf("%d",&n)

int main()
{
	int t;
	gN(t);
	while(t-- > 0)
	{
		int n;
		gN(n);
		int k = (n/2) + 1;
		printf("%d\n",k);
	}
	return 0;
}