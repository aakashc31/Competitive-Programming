/*For each segment of length k store the prefix and suffix max
First initiate*/
// And ofcourse this was better than arraysub.cpp Ran faster

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

vvi prefix_max(0);
vvi suffix_max(0);

int ar[1000000];
int n,k;

void init_prefix_max(int low, int high)
{
	vi temp(0);
	temp.pb(ar[low]);
	int m = ar[low];
	fab(i, low+1, high)
	{
		m = max(m,ar[i]);
		temp.pb(m);
	}
	prefix_max.pb(temp);
}

void init_suffix_max(int low, int high)
{
	vi temp(high-low+1,0);
	int last = high-low;
	temp[last] = ar[high];
	int m = ar[high];
	for(int i=high-1; i>=low; i--)
	{
		m = max(m, ar[i]);
		temp[last-1] = m;
		last--;
	}
	suffix_max.pb(temp);
}


void initiate()
{
	int low = 0, high = low+k-1;
	while(high < n)
	{
		init_suffix_max(low, min(high,n-1));
		init_prefix_max(low, min(high,n-1));
		low += k, high += k;
	}
}

int query_prefix(int i)
{
	return prefix_max[i/k][i%k];
}

int query_suffix(int i)
{
	return suffix_max[i/k][i%k];
}

int main()
{
	g(n);
	f(i,n) g(ar[i]);
	g(k);
	initiate();
	int low = 0, high = low+k-1;
	while(high < n)
	{
		printf("%d ", max(query_suffix(low), query_prefix(high)));
		low++, high++;
	}
	printf("\n");
	return 0;
}