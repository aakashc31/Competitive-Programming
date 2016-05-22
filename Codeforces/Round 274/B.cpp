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

int ar[105];
pii ans[1005];
int index;
int instab[1005]; //this was the error!!!!
int main()
{
	index = 0;
	int n,k,s,m;
	g(n),g(k);
	f(i,n) g(ar[i]);
	
	int max_ind, min_ind,sn,max_ind_n, min_ind_n;
	max_ind = max_element(ar,ar+n)-ar;
	min_ind = min_element(ar,ar+n)-ar;
	s = ar[max_ind] - ar[min_ind];
	instab[0] = s;
	while(index<k && s>0)
	{
		ans[index++] = mp(max_ind+1, min_ind+1);
		
		ar[max_ind]--;
		ar[min_ind]++;
		max_ind = max_element(ar,ar+n)-ar;
		min_ind = min_element(ar,ar+n)-ar;
		s = ar[max_ind] - ar[min_ind];
		instab[index] = s;
	}
	int pind = 0;
	while(instab[pind]!=s) pind++;
	printf("%d %d\n",s,pind);
	f(i,pind) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}