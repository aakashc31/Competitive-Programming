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
	int t,n,k,a;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		int s = 0;
		for(int i=0; i<n; i++)
		{
			cin >> a;
			s += a;
			s %= 2;
		}
		if(s == 0)
		{
			if(k==1)
				cout << "odd" << endl;
			else 
				cout << "even" << endl;
		}
		else
		{
			cout << "even" << endl;
		}

	}
	return 0;
}