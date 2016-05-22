#include <stdio.h>

int fun(int n)
{
	int a=0,b=1,l=2;
	while(a!=(n-1)||(b!=1))
	{
		int temp = (a+b)%n;
		a = b;
		b = temp;
		l++;
	}
	return l;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=2;i<=t;i++)
		// printf("%d, ",fun(i));
		{fun(i);printf("%d,",i);}	
	return 0;
}