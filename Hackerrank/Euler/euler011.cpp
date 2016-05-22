#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;

int main()
{
	int ar[20][20];
	int n=20;
	f(i,n)
	{
		f(j,n)
			getNum(ar[i][j]);
	}
	int max = 0;
	// 
	// left to right
	f(i,n)
	{
		f(j,17)
		{
			int pdt = ar[i][j]*ar[i][j+1]*ar[i][j+2]*ar[i][j+3];
			if(pdt>max)
				max=pdt;
		}
	}
	// up-down
	f(j,n)
	{
		f(i,17)
		{
			int pdt = ar[i][j]*ar[i+1][j]*ar[i+2][j]*ar[i+3][j];
			if(pdt>max)
				max=pdt;
		}
	}
	// diagonally
	f(k,17)
	{
		int i=0;
		int j=k;
		for(;j<=16;j++,i++)
		{
			int pdt = ar[i][j]*ar[i+1][j+1]*ar[i+2][j+2]*ar[i+3][j+3];
			if(pdt>max)
				max=pdt;
		}
	}
	f(k,17)
	{
		int j=0;
		int i=k;
		for(;i<=16;i++,j++)
		{
			int pdt = ar[i][j]*ar[i+1][j+1]*ar[i+2][j+2]*ar[i+3][j+3];
			if(pdt>max)
				max=pdt;
		}
	}
	// right diagonal
	for(int k=3;k<=16;k++)
	{
		int i=0; int j=k;
		for(;j>=3;j--,i++)
		{
			int pdt = ar[i][j]*ar[i+1][j-1]*ar[i+2][j-2]*ar[i+3][j-3];
			if(pdt>max)
				max=pdt;
		}
	}

	// for(int k=3;k<=16;k++)
	// {
	// 	int i=k; int j=0;
	// 	for(;i>=3;j++,i--)
	// 	{
	// 		int pdt = ar[i][j]*ar[i-1][j-1]*ar[i-2][j-2]*ar[i-3][j-3];
	// 		if(pdt>max)
	// 			max=pdt;
	// 	}
	// }
	for(int k=3;k<=16;k++)
	{
		int i=19; int j=k;
		for(;j<=16;j++,i--)
		{
			int pdt = ar[i][j]*ar[i-1][j+1]*ar[i-2][j+2]*ar[i-3][j+3];
			if(pdt>max)
				max=pdt;
		}
	}
	printf("%d\n",max);
}