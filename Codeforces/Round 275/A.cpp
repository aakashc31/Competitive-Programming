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
	lli l, r;
	gl(l),gl(r);
	if(r-l+1 < 3)
		printf("-1\n");
	else
	{
		if((l&1) && (r-l+1 == 3))
			printf("-1\n");
		else
		{
			if(l&1)
				l++;
			printf("%lld %lld %lld\n",l,l+1,l+2);
		}
	}
	return 0;
}