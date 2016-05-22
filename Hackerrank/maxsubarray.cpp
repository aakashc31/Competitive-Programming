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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


int main()
{
	int t,n;
	int ar[100000];
	cin >> t;
	while(t--)
	{
		cin >> n;
		f(i,n) cin >> ar[i];
		int maxAr = *max_element(ar, ar+n);
		int ans2 = 0;
		// 
		if(maxAr < 0)
			ans2 = maxAr;
		else
		{
			ans2 = 0;
			f(i,n)
			{
				if(ar[i] > 0)
					ans2 += ar[i];
			}
		}
		// 

		int max_ending_here = ar[0];
		int max_till_now = ar[0];

		for(int i=1; i<n; i++)
		{
			max_ending_here = max(max_ending_here + ar[i], ar[i]);
			max_till_now = max(max_ending_here, max_till_now);
		}

		cout << max_till_now << " " << ans2 << endl;
	}
	return 0;
}