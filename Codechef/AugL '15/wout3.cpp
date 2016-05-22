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

struct node
{
	int count;
}ar[20000000];


//i: index, (l,r): range of current node, (from,to): range to be updated
void update(int i, int l, int r, int from, int to)
{
	//if disjoint: return
	if(r<from || l>to)
		return;

	//handle leaf node
	if(l==r)
	{
		ar[i].count++;
		return;
	}

	//if (l,r) is subset of (from, to) : increment and return
	if(l>=from && r<=to)
	{
		ar[i].count++;
		return;
	}

	//else recursively call intersection
	else
	{
		int mid = (l+r)/2;
		update(2*i, l, mid, from, to);
		update(2*i+1, mid+1,r,from,to);
	}
}

int query(int i, int l, int r, int n)
{
	if(n<l || n>r)
		return 0;
	if(l==r)
		return ar[i].count;
	int mid = (l+r)/2;
	if(n<=mid)
		return ar[i].count + query(2*i,l,mid,n);
	else
		return ar[i].count + query(2*i+1,mid+1,r,n);
}

int compute(int n)
{
	int cpy = n;
	int cnt = 0;
	while(n!=1)
	{
		cnt++;
		n = (n>>1);
	}
	if(cpy == (1<<cnt))
	{
		// printf("compute(%d) = %d\n",cpy,2*cpy);
		return 2*cpy;
	}
	// printf("compute(%d) = %d\n",cpy,(1<<(cnt+2)));
	return (1<<(cnt+2));
}

int main()
{
	int t,n,h;
	cin >> t;
	bool isLess = (t<=100);
	while(t--)
	{
		cin >> n >> h;
		memset(ar, 0, 4*2097152);
		f(i,n)
		{
			int lower, upper;
			cin >> lower >> upper;
			update(1,0,n -1,lower,upper);
		}

		int base = 0;
		int ceiling = base + h - 1;
		ll ans = 0;
		for(int i=base; i<=ceiling; i++)
		{
			ll gapsInRow = query(1,0,n-1,i);
			// cout << "gapsInRow " << i << "  = " << gapsInRow << endl;
			ans += (n-gapsInRow);
		}
		ll curr = ans;
		ceiling++; base++;
		// cout << "ans = " << ans << ", base = " << base-1 << endl;
		while(ceiling < n)
		{
			ll sub = n-query(1,0,n-1,base-1);
			ll add = n-query(1,0,n-1,ceiling);
			curr = curr + add - sub;
			if(curr < ans) ans = curr;
			ceiling++; base++;
			// cout << "ans = " << ans << ", base = " << base-1 << endl;
		}

		cout << ans << endl;
	}
	return 0;
}
