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
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int dp1[200001];
int dp2[200001];

int main()
{
	int t;
	string l1, l2;
	cin >> t;
	while(t--)
	{
		cin >> l1 >> l2;
		int l = l1.length();
		
		for(int i=0; i<l; i++)
			dp1[i] = dp2[i] = (1<<30);

		dp1[0] = (l1[0] == '.') ? 0 : (1<<30);
		dp2[0] = (l2[0] == '.') ? 0 : (1<<30);

		for(int i=1; i<l; i++)
		{
			if(l1[i] == '.')
			{
				dp1[i] = dp1[i-1];
				dp1[i] = min(dp1[i], dp2[i-1]+1);
			}

			if(l2[i] == '.')
			{
				dp2[i] = dp2[i-1];
				dp2[i] = min(dp2[i], dp1[i-1]+1);
			}
		}
		int ans = min(dp1[l-1], dp2[l-1]);
		if(ans >= (1<<30))
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl << ans << endl;
		}

	}
	return 0;
}