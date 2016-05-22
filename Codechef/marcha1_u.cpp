#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n,m;
		getNum(n);
		getNum(m);
		int ar[n];
		f(i,n)
		{
			getNum(ar[i]);
		}
		unsigned int numSubsets = pow(2.0,float(n));
		int flag = 0;
		for(unsigned int i=1; i<numSubsets; i++)
		{
			int sum = 0;
			for(int j=0; j<n; j++)
			{
				if(i&(1<<j))
				{
					sum+=ar[j];
				}
			}
			if(sum == m)
			{
				printf("Yes\n");
				flag = 1;
				break;
			}
		}
		if(flag==0)
			printf("No\n");
	}
	return 0;
}
