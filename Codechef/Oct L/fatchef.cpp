#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,char> pic;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
const int modulo = 1000000009;
bool comp(const pic& a,const pic& b)
{
	return a.first < b.first;
}
pic ar[100000];
int main()
{
	int t,n,m,a;
	char ch; lli ans;
	g(t);
	while(t--)
	{
		ans = 1;
		g(n),g(m);
		f(i,m)
		{
			cin >> ch;
			g(a);
			a--;
			ar[i] = mp(a,ch);
		}
		sort(ar,ar+m,comp);
		// f(i,m) printf("%d - %c\n",ar[i].first,ar[i].second);
		f(i,m-1)
		{
			if(ar[i].second != ar[i+1].second)
			{
				ans = (ans*(ar[i+1].first - ar[i].first))%modulo;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}