#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

typedef long long int lli;

int ar[100000];
bool is_sorted(int n)
{
	bool f = true;
	f(i,n-1)
	{
		if(ar[i] > ar[i+1])
		{
			f = false;
			break;
		}
	}
	return f;
}
int main()
{
	int n;
	getNum(n);
	f(i,n)
		getNum(ar[i]);
	if(is_sorted(n))
	{
		printf("yes\n1 1\n");
		return 0;
	}
	int left = -1, right = n;
	int min = 0;
	int max = 1000000001;
	while(min < ar[left+1])
		left++, min = ar[left];
	// printf("Left = %d\n",left );
	while(max > ar[right-1])
		right--, max = ar[right];
	// printf("Right = %d\n",right);
	bool flag = true;
	fab(i,left,right-1)
	{
		if(ar[i] <= ar[i+1])
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		f(i,left)
		{	
			if(ar[i] > ar[right])
			{
				flag = false;
				break;
			}
		}
		fab(i,right+1,n-1)
		{
			if(ar[i] < ar[left])
			{
				flag = false;
				break;
			}
		}
	}
	if(flag)
	{
		printf("yes\n%d %d\n",left+1,right+1);
	}
	else
		printf("no\n");
	return 0;
}