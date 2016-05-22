#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int n = 3, m = 3;
	int ar[n*m];
	f(i,n*m)
		ar[i] = i+1;
		printf("375840\n");

	do
	{
		printf("3 3\n2 0 1\n");
		f(i,n)
		{
			f(j,m)
			{
				printf("%d ",ar[i*m + j] -1);
			}
			printf("\n");
		}
		// printf("\n\n");

	}while(next_permutation(ar,ar+n*m));
	return 0;
}