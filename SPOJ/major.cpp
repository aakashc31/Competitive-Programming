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
int ar[2001];
int main()
{
	int a,t,n;
	g(t);
	test(t)
	{
		g(n);
		memset(ar,0,sizeof ar);
		f(i,n)
		{
			g(a);
			if(a>=0) ar[a]++;
			else ar[1000-a]++;
		}
		bool flag = false;
		f(i,2001)
		{
			if(ar[i] > n/2)
			{
				flag = true;
				if(i<=1000)
					printf("YES %d\n",i);
				else
					printf("YES %d\n",1000-i);
			}
		}
		if(!flag)
			printf("NO\n");
	}
	return 0;
}