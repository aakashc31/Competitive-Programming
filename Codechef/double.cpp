#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t-- > 0)
	{
		int i;
		scanf("%d",&i);
		if(i%2==0)
			printf("%d\n",i);
		else
			printf("%d\n",i-1);
	}
	return 0;
}