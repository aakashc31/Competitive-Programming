#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
typedef long long int lli;

int getPairs(int* ar, int len, int k)
{
	int ans = 0, temp;
	for(int i=1; i<len; i++)
	{
		temp = lower_bound(ar,ar+i,ar[i]-k)-ar;
		// printf("%d - %d\n",ar[i],temp);
		temp = i - temp;
		ans+=temp;
	}
	return ans;
}

int main()
{
	int ar[] = {1,2,2,3};
	printf("%d\n", getPairs(ar,4,1));
	return 0;
}