#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define mp make_pair

int main()
{
	int ar[] = {1,2,4,5,6};
	printf("%d\n",lower_bound(ar,ar+5,4)-ar );
	return 0;
}