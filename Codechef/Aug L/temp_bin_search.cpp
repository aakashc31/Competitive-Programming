#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)

int num_smaller_elements(int* ar, int len, int n)
{
	if(ar[0] >= n)
		return 0;
	if(ar[len-1] < n)
		return len;
	if(len==1 && ar[0] < n)
		return 1;
	int mid = len/2;
	if(ar[mid-1] < n && n <= ar[mid] )
		return mid;
	if(ar[mid] < n)
		return 1+mid+ num_smaller_elements(ar+mid+1, len-mid-1, n);
	else
		return num_smaller_elements(ar,mid+1,n);
}
int num_larger_elements(int* ar, int len, int n)
{
	if(ar[0] > n)
		return len;
	if(ar[len-1] <= n)
		return 0;
	if(len==1 && ar[0] > n)
		return 1;
	int mid = len/2;
	if(ar[mid-1] <= n && n < ar[mid] )
		return (len-mid);
	if(ar[mid] <= n)
		return num_larger_elements(ar+mid+1, len-mid-1, n);
	else
		return (len-mid)+num_larger_elements(ar,mid,n);
}

int main()
{
	int ar[] = {0,1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",num_larger_elements(ar,11,9));
	return 0;
}