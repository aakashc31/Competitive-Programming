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

int compute(int s, int t)
{
	if(s==t) return 0;
	int power = isPowerOfTwo(t);
	int ret = 0;
	while(isPowerOfTwo(s) == -1)
	{
		s = (s>>1);
		ret++;
	}
	if(s == t)
		return ret;
	else if(s > t)
	{
		while(s!=t)
		{
			ret++;
			s = (s>>1);
		}
		return ret;
	}
	else
	{
		while(s!=t)
		{
			ret++;
			s = (s<<1);
		}
		return ret;
	}
}

int main()
{
	int t,A,B;
	cin >> t;
	while(t--)
	{
		cin >> A >> B;
		cout << compute(A,B) << endl;
	}
	return 0;
}
