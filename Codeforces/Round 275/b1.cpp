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
lli cnt1,cnt2,x,y,t,d,rem,p1,p2,a1;

bool isPossible(lli v)
{
	lli a1,a2,a3;
	a1 = v - (v/x);
	a2 = v - (v/y);
	a3 = v - (v/(x*y));
	if( a1>=cnt1 && a2>=cnt2 && a3>=(cnt1+cnt2))
		return true;
	return false;
}

lli binary_search(lli low, lli high)
{
	if(low==high)
		return low;
	lli mid = low + (high-low)/2;
	if(isPossible(mid) && !isPossible(mid-1))
		return mid;
	if(!isPossible(mid) && isPossible(mid+1))
		return mid+1;
	else if(isPossible(mid))
		return binary_search(low, mid-1);
	else
		return binary_search(mid+1,high);
}

int main()
{
	
	gl(cnt1); gl(cnt2); gl(x); gl(y);
	
	printf("%lld\n",binary_search(1,x*y*(cnt2+cnt1)));
	return 0;
}