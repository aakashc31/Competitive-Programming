#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)


int binarysearch(int arr[], int l, int r, int search)
{
	if(l>r)
		return -1;
	int mid = (l+r)/2;
	if(arr[mid]==search)
		return mid;
	else if(arr[mid] > search)
		return binarysearch(arr,l,mid-1,search);
	else
		return binarysearch(arr,mid+1,r,search);
}

int ar[100000]; //co-ordinates
int sorted_ar[100000];
int range[100000];
int main()
{
	int n,k,p;
	getNum(n), getNum(k), getNum(p);
	f(i,n)
	{
		getNum(ar[i]);
		sorted_ar[i] = ar[i];
	}

	sort(sorted_ar,sorted_ar+n);
	range[0] = 0;
	for(int i=1;i<n;i++)
	{
		if(sorted_ar[i] - sorted_ar[i-1] <=k)
			range[i] = range[i-1]+1;
		else
			range[i] = range[i-1];
	}
	// f(i,n)
	// 	printf("range[%d] = %d\n",i,range[i] );
	f(i,p)
	{
		int p1,p2;
		getNum(p1),getNum(p2);
		int i1 = binarysearch(sorted_ar,0,n-1,ar[p1-1]);
		int i2 = binarysearch(sorted_ar,0,n-1,ar[p2-1]);
		int imax = max(i1,i2);
		int imin = min(i1,i2);
		if(range[imax]-range[imin] == (imax-imin))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
