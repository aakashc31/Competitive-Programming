#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

// converts n into base "base" ans stores in array ar[], starting from index "size", also updates size to new size
void convertToBaseN(int n, int ar[], int &size, int base)
{
	int cpy = size;
	if(n==0)
	{
		ar[size++]=0;
		return;
	}
	while(n>0)
	{
		ar[size++]=n%base;
		n/=base;
	}
	int i=cpy, j=size-1;
	while(j>=i)
	{
		swap(ar[i],ar[j]);
		j--,i++;
	}
}

int main()
{
	int n;
	// printf("%c\n",alpha[2]);
	scanf("%d",&n);
	f(i,n+1)
	{
		
	}
	return 0;
}