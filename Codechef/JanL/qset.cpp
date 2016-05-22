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

struct node
{
	int pref_mod[3];
	int suff_mod[3];
	int num_sub;
};


