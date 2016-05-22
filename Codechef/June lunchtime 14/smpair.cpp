#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
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
		f(i,n)
			getNum(ar[i]);
		sort(ar,ar+n);
		printf("%d\n",ar[0]+ar[1]);
	}
	return 0;
}
