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
	int A[100000], pref[100000], suff[100000];
	int t,n,q,l,r;
	g(t);
	test(t)
	{
		g(n),g(q);
		f(i,n) g(A[i]);
		pref[0] = A[0];
		for(int i=1; i<n; i++)
			pref[i] = __gcd(pref[i-1], A[i]);
		suff[n-1] = A[n-1];
		for(int i=n-2; i>=0; i--)
			suff[i] = __gcd(suff[i+1], A[i]);
		f(i,q)
		{
			g(l), g(r);
			l--,r--;
			int t1 = 1, t2 = 1;
			if(l>0) t1 = pref[l-1];
			if(r< n-1) t2 = suff[r+1];
			if(l==0) t1 = t2;
			if(r==n-1) t2 = t1;
			printf("%d\n", __gcd(t1,t2));
		}
	}
	return 0;
}