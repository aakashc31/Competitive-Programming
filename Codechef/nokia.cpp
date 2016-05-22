#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)
int inputInteger()
{
	char ch = inpch;
	int r=0;
	while(ch!='\n' && ch!=' ')
	{
		r = r*10 + ch-'0';
		ch = inpch;
	}
	return r;
}
int ar[] = {0,2, 5, 8, 12, 16, 20, 24, 29, 34, 39, 44, 49, 54, 59, 64, 70, 76, 82, 88, 94, 100, 106, 112, 118, 124, 130, 136, 142, 148, 154};
int ar2[] = {0,2, 5, 9, 14, 20, 27, 35, 44, 54, 65, 77, 90, 104, 119, 135, 152, 170, 189, 209, 230, 252, 275, 299,324, 350, 377, 405, 434, 464, 495};
	
int main()
{
	int t,n,m,max,minn;
	t = inputInteger();
	while(t--)
	{
		n=inputInteger(), m=inputInteger();
		max = ar2[n];
		minn = ar[n];
		if(minn<=m && m<=max)
			printf("0\n");
		else if(m>max)
			printf("%d\n",m-max);
		else
			printf("-1\n");
	}	
	return 0;
}