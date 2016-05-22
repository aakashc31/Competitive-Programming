#include <iostream>
#include <stdio.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		int n;
		scanf("%d",&n);
		if(n%2==0)
			printf("ALICE\n");
		else
			printf("BOB\n");
	}
	return 0;
}