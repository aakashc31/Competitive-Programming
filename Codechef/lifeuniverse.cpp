#include <iostream>
#include <stdio.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)
int main()
{
	int i;
	getNum(i);
	while(i!=42)
	{
		printf("%d\n",i);
		getNum(i);
	}
	return 0;
}