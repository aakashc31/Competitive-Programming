#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int main()
{
	int n, k;
	g(n),g(k);
	printf("1 ");
	int diff = k, sign = 1,prev=1;
	while(diff>0)
	{
		prev = prev + sign*diff;
		printf("%d ",prev);
		if(sign>0)
			sign=-1;
		else
			sign = 1;
		diff--;
	}
	fab(i,k+2,n) printf("%d ",i);
	printf("\n");
	return 0;
}