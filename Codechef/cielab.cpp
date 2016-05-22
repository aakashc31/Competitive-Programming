#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int d = a-b;
	if(d%10==9)
		d-=1;
	else
		d+=1;
	printf("%d\n",d);
	return 0;
}