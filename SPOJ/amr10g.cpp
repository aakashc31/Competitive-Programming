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

int ar[20000];
int t,k,n,ans;
int main()
{
	g(t);
	test(t)
	{
		g(n),g(k);
		f(i,n) g(ar[i]);
		sort(ar, ar+n);
		ans = ar[k-1]-ar[0];
		for(int i=1; (i+k-1)<n; i++)
		{
			if(ar[i+k-1]-ar[i] < ans)
				ans = ar[i+k-1]-ar[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}