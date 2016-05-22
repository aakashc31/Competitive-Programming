#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
typedef long long int lli;


int main()
{
	int ar[] = {1,2,3,5,6,7,9,10};
	printf("%d\n",lower_bound(ar,ar+8,2)-ar);
	return 0;
}