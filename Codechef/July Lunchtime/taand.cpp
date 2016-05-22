#include <bits/stdc++.h>

using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;

int ar[300000];
int main()
{
	int n;
	getNum(n);
	f(i,n) getNum(ar[i]);
	int max = 0;
	f(i,n)
	{
		for(int j = i+1; j<n; j++)
		{
			int val = ar[i]&ar[j];
			if(val > max)
				max = val;
		}
	}
	printf("%d\n",max);
	return 0;
}