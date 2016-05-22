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

int ar[6];

int main()
{
	int a,b,c,m;
	g(a),g(b),g(c);
	ar[0] = (a*b)+c;
	ar[1] = (a+b)+c;
	ar[2] = (a*b)*c;
	ar[3] = (a+b)*c;
	ar[4] = a*(b+c);
	ar[5] = a+(b*c);
	m = ar[0];
	fab(i,1,5)
	{
		if(ar[i] > m)
			m = ar[i];
	}
	printf("%d\n",m);
	return 0;
}