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

pii ar[5000];
bool flag[5000];
int n;

int main()
{
	int a,b,msel;
	g(n);
	f(i,n)
	{
		g(a),g(b);
		ar[i] = mp(a,b);
	}
	sort(ar,ar+n);
	flag[0] = true;
	fab(i,1,n-1) flag[i] = false;
	fab(i,1,n-1)
	{
		int smIndex = i-1;
		while(ar[i].first == ar[smIndex].first && smIndex >= 0)
			smIndex--;
		if(smIndex == -1) //it is smallest
			flag[i] = true;
		else //now you have the index of the paper just smaller than this
		{
			if(flag[smIndex]) //b[sm] is selected
				msel = ar[smIndex].second;
			else
				msel = ar[smIndex].first;
			if(ar[i].second >= msel)
				flag[i] = true;
		}
	}
	int end = ar[0].second, val;
	fab(i,1,n-1)
	{
		val = (flag[i])?ar[i].second : ar[i].first;
		if(val > end)
			end = val;
	}
	printf("%d\n",end);
	return 0;
}