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

int ar[100000];
int n,l,x,y;

bool exists_diff(int* ar, int len, int d)
{
	int val;
	f(i,len)
	{
		val = ar[i]+d;
		if(binary_search(ar,ar+len,val))
			return true;
	}
	return false;
}

int main()
{
	g(n); g(l); g(x); g(y);
	f(i,n) g(ar[i]);
	bool p1 = exists_diff(ar,n,x);
	bool p2 = exists_diff(ar,n,y);
	if(p1 && p2)
		printf("0\n");
	else if(p1 && (!p2))
		printf("1\n%d\n",y);
	else if((!p1) && p2)
		printf("1\n%d\n",x);
	else
	{
		// check for ek teer se do nishaane
		bool flag = false;
		int ans,val;
		f(i,n)
		{
			val = ar[i];
			ans = val+x;
			if((binary_search(ar,ar+n,ans-y) || binary_search(ar,ar+n,ans+y)) && ((ans>=0 && ans<=l)))
			{
				flag = true;
				break;
			}
			ans = val-x; //here you assumed that you can always make a cut at val-x
			if((binary_search(ar,ar+n,ans-y) || binary_search(ar,ar+n,ans+y)) && (ans>=0 && ans<=l))
			{
				flag = true;
				break;
			}
			ans = val+y;
			if((binary_search(ar,ar+n,ans-x) || binary_search(ar,ar+n,ans+x)) && (ans>=0 && ans<=l))
			{
				flag = true;
				break;
			}
			ans = val-y;
			if((binary_search(ar,ar+n,ans-x) || binary_search(ar,ar+n,ans+x)) && (ans>=0 && ans<=l))
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			printf("1\n%d",ans);
		}
		else
		{
			printf("2\n%d %d\n",x,y);
		}
	}
	return 0;
}