#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0 ;i<n; i++)
#define getcx getchar//_unlocked
#define g(n) inp(n)//scanf("%lld",&n)
typedef long long int lli;

inline void inp(int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int days(int n, int m, int offset)
{
	int new_socks = (n+offset)/m;
	if(new_socks==0)
		return n;
	else
		return n+ days(new_socks,m,(n+offset)%m);
}

int main()
{
	int n,m;
	g(n),g(m);
	printf("%d\n",days(n,m,0));
	return 0;
}