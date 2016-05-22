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
	int t,n;
	pii ar[100000];
	g(t);
	test(t)
	{
		g(n);
		f(i,n)
		{
			int a,b;
			g(a),g(b);
			ar[i] = mp(a,b);
		}
		sort(ar,ar+n);
		int bombs = 0;
		int i = 1;
		int curr_left = ar[0].first, curr_right = ar[0].second;
		while(i < n)
		{
			if(ar[i].first > curr_right)
			{
				bombs++;
				curr_left = ar[i].first, curr_right = ar[i].second;
			}
			else
			{
				if(ar[i].second <= curr_right) //this means ar[i] is subset
				{
					curr_left = ar[i].first, curr_right = ar[i].second;
				}

				else
				{
					curr_left = ar[i].first;
				}
			}
			i++;
		}
		bombs++;
		printf("%d\n",bombs);
	}
	return 0;
}