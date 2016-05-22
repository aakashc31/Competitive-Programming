#include <iostream>
#include <stdio.h>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n;
		getNum(n);
		int ar[n];
		f(i,n)
		{
			int temp;
			getNum(temp);
			ar[i] = temp-1;
		}
		int numInv = 0;
		f(i,n)
		{
			f(j,i)
			{
				if(ar[j] > ar[i])
					numInv++;
			}
		}
		int localInv = 0; //this could have been computed simultaneously with the inputing part
		f(i,n-1)
		{
			if(ar[i] > ar[i+1])
				localInv++; 
		}
		if(localInv==numInv)
			printf("YES\n");
		else
			printf("NO\n");
	}
}