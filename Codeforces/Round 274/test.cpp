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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


int compute(pii* ar, int len, int bitmask)
{
	int end = 0;
	f(i,len)
	{
		int val = (bitmask&1)?ar[i].second : ar[i].first;
		bitmask/=2;
		if(val>end)
			end = val;
	}
	return end;
}

int main()
{
	int a,b;
	pii ar[10];
	f(i,10) 
	{
		g(a),g(b);
		ar[i] = mp(a,b);
	}
	int m = 1000000000;
	f(b,1024)
	{
		m = min(m,compute(ar,10,b));
	}
	printf("%d\n",m);
	return 0;
}