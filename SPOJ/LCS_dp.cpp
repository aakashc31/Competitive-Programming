
// using dynamic programming O(n^2):
// Slow for test cases as large as n=250000
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getStr(s) scanf("%s",&s)

int a1[250000];
int a2[250000];
char A[250001];
char B[250001];
int main()
{
	int max=0;
	getStr(A);
	getStr(B);
	int l1 = strlen(A);
	int l2 = strlen(B);
	
	// base case: setting value of a1, that is LCS[i][0] for all i
	f(i,l1)
	{
		if(A[i]==B[0])
		{
			max=1;
			a1[i] = 1;
		}
		else
			a1[i] = 0;
	}

	f(j,l2)
	{
		int* anext;
		int* aprev;
		if(j%2 == 0)
		{
			aprev = a2;
			anext = a1;
		}
		else
		{
			aprev = a1;
			anext = a2;
		}
		if(A[0]==B[j])
		{
			if(max==0) max=1;
			anext[0] = 1;
		}
		else
			anext[0] = 0;
		f(i,l1)
		{
			if(A[i]!=B[j])
				anext[i] = 0;
			else
			{
				anext[i] = aprev[i-1] + 1;
				// printf("%d,%d: %d\n", i, j, anext[i]);
				if(anext[i] > max)
					max = anext[i];
			}
		}
	}
	printf("%d\n",max);

	return 0;
}