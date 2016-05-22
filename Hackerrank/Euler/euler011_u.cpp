#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;
int ar[20][20];

bool isValid(int i, int j)
{
	if(i>=0 && j>=0 && i<20 && j<20)
		return true;
	else
		return false;
}

int check_dia(int i, int j)
{
	int max = 0;
	f(k,4)
	{
		int pdt = 0;
		if(isValid(i+k,j+k) && isValid(i-1+k,j-1+k) && isValid(i-2+k,j-2+k) && isValid(i-3+k,j-3+k))
		{
			pdt = ar[i+k][j+k]* ar[i-1+k][j-1+k] * ar[i-2+k][j-2+k] * ar[i-3+k][j-3+k];
		}
		if(pdt>max)
			max=pdt;
	}
	f(k,4)
	{
		int pdt = 0;
		if(isValid(i+k,j+k) && isValid(i-1+k,j+1+k) && isValid(i-2+k,j+2+k) && isValid(i-3+k,j+3+k))
		{
			pdt = ar[i+k][j+k]* ar[i-1+k][j+1+k] * ar[i-2+k][j+2+k] * ar[i-3+k][j+3+k];
		}
		if(pdt>max)
			max=pdt;
	}
	return max;
}
	
	

int main()
{
	
	int n=20;
	f(i,n)
	{
		f(j,n)
			getNum(ar[i][j]);
	}
	int max = 0;
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
	f(i,n)
	{
		f(j,n)
		{
			int pdt = check_dia(i,j);
			if(pdt>max)
				max=pdt;
		}
	}
	printf("%d\n",max);
	return 0;
}
