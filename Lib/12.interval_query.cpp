// page 89, IOITC notes
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

vi ar(0);
vvi tree(0);

void initialize_tree()
{
	tree.pb(ar);
	int s = ar.size();
	int low = 0, high = s-1, k=1;
	while(low + (1<<k) <= s)
	{
		int window = (1<<k);
		vi temp(0);
		for(int i=0; i+window <= s; i++)
		{
			temp.pb(max(tree[k-1][i], tree[k-1][i+window/2]));
		}
		k++;
		tree.pb(temp);
	}
}

void query(int i, int j)
{
	i--,j--;
	int ans = -15008,k;
	while(i<j)
	{
		k = 0;
		while(i+(1<<k) <= j) // well! (i+2^k) is the low index of the next window to be considered. And it should be <= j
			k++;
		k--;
		// largest k such that i + 2^k does not cross j
		ans = max(ans, tree[k][i]);
		i += (1<<(k));
	}
	if(i==j) ans = max(ans, ar[i]);
	printf("%d\n",ans);
}

int main()
{
	int n,q,a,b;
	g(n);
	f(i,n){
		g(a);
		ar.pb(a);
	}
	initialize_tree();
	g(q);
	while(q--)
	{
		g(a),g(b);
		query(a,b);
	}
	return 0;
}