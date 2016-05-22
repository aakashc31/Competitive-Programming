#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
typedef pair<int,int> pii;

pii interval[100000];
int cams[100000];

int main()
{
	int n,k,a,b;
	g(n),g(k);
	f(i,n) g(cams[i]);
	sort(cams,cams+n);
	f(i,k)
	{
		g(a),g(b);
		interval[i]=mp(min(a,b),max(a,b));
	}
	int cnt = 0;
	f(i,n)
	{
		int d = cams[i];
		f(j,k)
		{
			if(interval[j].first <= d && d <= interval[j].second)
			{
				printf("%d gone by %d,%d\n",d,interval[j].first,interval[j].second);
				cnt++;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}