#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int a,b,pdt;
	getNum(a), getNum(b);
	// if(a==b)
	// {
	// 	if(a&1)
	// 		printf("Akshat\n");
	// 	else
	// 		printf("Malvika\n");
	// 	return 0;
	// }
	int n = min(a,b);
	// int m = max(a,b);
	if(n&1)
		printf("Akshat\n");
	else
		printf("Malvika\n");
	return 0;
}