#include <iostream>
#include <stdio.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n,c;
		getNum(n);
		getNum(c);
		int s = 0;
		f(i,n)
		{
			int g;
			getNum(g);
			s+=g;
		}
		if(s<=c)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}