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

int main()
{
	int t;
	cin >> t;
	string s1,s2;
	while(t--)
	{
		cin >> s1 >> s2;
		int l = s1.length();
		bool ans = true;
		for(int i=0; i<l;i++)
		{
			if(s1[i]==s2[i])
				continue;
			else if(s1[i] == '?' || s2[i] == '?')
				continue;
			else
			{
				ans = false;
				break;
			}
		}

		if(ans)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}