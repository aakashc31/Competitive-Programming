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

const lli u = 1000000;
lli ar[u+1];

void init()
{
	for(lli i=0; i<=u; i++)
		ar[i] = i*i;
}

bool isSum(lli s)
{
	lli lb = 0, ub = u, temp;
	while(lb <= ub)
	{
		temp = ar[lb] + ar[ub];
		if(temp == s)
			return true;
		else if(temp < s)
			lb++;
		else
			ub--;
	}
	return false;
}

int main()
{
	init();
	lli n;
	int t;
	g(t);
	while(t--)
	{
		gl(n);
		if(isSum(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}