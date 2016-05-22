#include <iostream>
#include <stdio.h>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		int ar[n];
		int inverse[n];
		f(i,n)
		{
			int t;
			scanf("%d",&t);
			ar[i] = t-1;
			inverse[t-1] = i;
		}
		bool isAm = true;
		f(i,n)
		{
			if(ar[i]!=inverse[i])
			{
				isAm = false;
				break;
			}
		}
		if(isAm)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		scanf("%d",&n);
	}
}