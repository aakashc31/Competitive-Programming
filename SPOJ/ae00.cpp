#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int n;
	getNum(n);
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(i*i > n)
			break;
		for(int j=i;j<=n;j++)
		{
			if(i*j > n)
				break;
			s++;
		}
	}
	printf("%d\n",s);
	return 0;
}