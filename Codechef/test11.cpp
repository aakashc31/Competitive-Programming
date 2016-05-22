#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define inpch getchar()//_unlocked()
#define outch putchar//_unlocked
#define getNum(n) scanf("%d",&n)

void print(int a[], int n)
{
	f(i,n)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int n;
	getNum(n);
	int ar[n];
	f(i,n) ar[i] =  i+1;
	int t;
	getNum(t);
	while(t==0)
	{
		print(ar,n);
		next_permutation(ar,ar+n);
		getNum(t);
	}
}