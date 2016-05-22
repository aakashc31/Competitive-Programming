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
	int t,n,k,temp;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int count = 0;
		f(i,n)
		{
			cin >> temp;
			if(temp <= 0)
				count++;
		}
		if(count < k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}