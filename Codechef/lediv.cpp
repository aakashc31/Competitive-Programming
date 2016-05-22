#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		getNum(n);
		int ar[n];
		int min = 100001;
		f(i,n)
		{
			getNum(ar[i]);
			if(ar[i] < min)
				min = ar[i];
		}
		if(min == 1)
		{
			printf("-1\n");
			continue;
		}
		int sq = sqrt(min);
		int arl[sq];
		int arr[sq+1];
		int l=0,r=1;
		arr[0] = min;
		for(int i=2; i<=sq;i++)
		{
			if(min%i==0)
			{
				arl[l++] = i;
				arr[r++] = min/i;
			}
		}
		bool flag = false;
		f(i,l)
		{
			bool allDiv = true;
			f(j,n)
			{
				if(ar[j]%arl[i]!=0)
				{
					allDiv = false;
					break;
				}
			}
			if(allDiv)
			{
				flag = true;
				printf("%d\n",arl[i]);
				break;
			}
		}

		if(!flag)
		{
			bool rflag = false;
			f(i,r)
			{
				bool allDiv = true;
				f(j,n)
				{
					if(ar[j]%arr[r-1-i]!=0)
					{
						allDiv = false;
						break;
					}
				}
				if(allDiv)
				{
					rflag = true;
					printf("%d\n",arr[r-1-i]);
					break;
				}
			}
			if(!rflag)
				printf("-1\n");
		}
	}
	return 0;
}