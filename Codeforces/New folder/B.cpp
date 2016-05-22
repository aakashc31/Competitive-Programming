#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	int n,m;
	getNum(n), getNum(m);
	if(n==0)
	{
		printf("0 1\n");
		printf("0 %d\n",m);
		printf("0 0\n");
		printf("0 %d\n",m-1);
	}
	else if(m==0)
	{
		printf("1 0\n");
		printf("%d 0\n",n);
		printf("0 0\n");
		printf("%d 0\n",n-1);
	}
	else if(n>m)
	{
		printf("0 0\n");
		printf("%d %d\n",n,m);
		printf("0 %d\n",m);
		printf("%d 0\n",n);
	}
	else
	{
		printf("0 0\n");
		printf("%d %d\n",n,m);
		printf("%d 0\n",n);
		printf("0 %d\n",m);
	}
	return 0;
}