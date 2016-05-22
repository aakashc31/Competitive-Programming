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
	int c = 5;
	printf("%d\n",c);
	int n = 987, m=500;
	int ar[n];
	f(i,n)
		ar[i] = i;
	while(c--)
	{
		
		printf("%d %d\n",n,m);
		random_shuffle(ar,ar+n);
		f(i,n)
			printf("%d ",ar[i]);
		printf("\n");

	}
	return 0;
}