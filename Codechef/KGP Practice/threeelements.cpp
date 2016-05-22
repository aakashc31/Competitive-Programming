#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
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

inline void inp(int &n)//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int ar[100];
int main()
{
	int t,n,num=1;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) g(ar[i]);
		sort(ar, ar+n);
		int s = ar[n-1] + ar[n-2] + ar[n-3];
		printf("Case %d: %d\n",num,s);
		num++;
	}
	return 0;
}