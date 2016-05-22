#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define test(t) while(t--)
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int gcdArray(int *ar, int n)
{
	if(n==1) return ar[0];
	int g = __gcd(ar[0],ar[1]);
	fab(i,2,n-1)
		g = __gcd(g,ar[i]);
	return g;
}

int main()
{
	int t,n;
	int ar[50];
	g(t);
	test(t)
	{
		g(n);
		f(i,n) g(ar[i]);
		int g = gcdArray(ar,n);
		f(i,n) printf("%d ",ar[i]/g);
		printf("\n");
	}
	return 0;
}