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

int isPowerOfTwo(int n)
{
	for(int i=0; i<32; i++)
	{
		if((1<<i) == n)
			return i;
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n==1)
			cout << "2" << endl;
		else if(n%2 == 0)
			cout << "-1" << endl;
		else
		{
			int p = isPowerOfTwo(n+1);
			if(p == -1)
				cout << "-1" << endl;
			else
			{
				// n = 2**p - 1
				//ans = 2**(p-1) - 1
				cout << (1<<(p-1))-1 << endl;
			}
		}
	}
	return 0;
}