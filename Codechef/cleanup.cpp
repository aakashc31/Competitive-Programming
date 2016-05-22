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

int main()
{
	int n,m,a,t;
	int *ar = new int[1000];
	g(t);
	test(t)
	{
		g(n),g(m);
		memset(ar,0,(4*n));
		f(i,m)
		{
			g(a);
			ar[a-1]=1;
		}
		bool flag = true;
		vi chef(0); vi ass(0);
		f(i,n)
		{
			if(ar[i]==1)
				continue;
			if(flag) chef.pb(i+1), flag = false;
			else ass.pb(i+1), flag = true;
		}
		f(i,chef.size()) printf("%d ",chef[i]);
		printf("\n");
		f(i,ass.size()) printf("%d ",ass[i]);
		printf("\n");
	}
	return 0;
}