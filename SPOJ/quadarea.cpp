#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define gd(n) scanf("%lf", &n);
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

int t;
int main()
{
	g(t);
	double a,b,c,d,s,ans;
	test(t)
	{
		gd(a); gd(b); gd(c); gd(d);
		s = (a+b+c+d)/2.0;
		ans = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%lf\n",ans);
	}
	return 0;
}