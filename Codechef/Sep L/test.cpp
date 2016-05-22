#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

int main()
{
	srand (time(NULL));
	int n = 200000;
	int m = n;
	printf("%d %d\n",n,m);
	f(i,n) printf("%d ",(rand()%n)+1);
	f(i,n) printf("%d %d\n",100,n-100);
	return 0;
}