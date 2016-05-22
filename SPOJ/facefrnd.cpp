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
	int n,a,b,m;
	g(n);
	set<int> f;
	set<int> fof;
	while(n--)
	{
		g(a);
		f.insert(a);
		if(fof.find(a)!=fof.end())
			fof.erase(fof.find(a));
		g(m);
		while(m--)
		{
			g(b);
			if(f.find(b)==f.end())
				fof.insert(b);
		}
	}
	printf("%d\n",fof.size());
	return 0;
}