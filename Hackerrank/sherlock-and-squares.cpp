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
	int t,a,b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		int z = sqrt(a);
		int low = (z*z == a) ? z-1 : z;
		int c = sqrt(b) - low;
		cout << c << endl;
	}
	return 0;
}