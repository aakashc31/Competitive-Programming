#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0;i<n;i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define g(n) inp(n)
#define getcx getchar//_unlocked
inline void inp( lli &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int main()
{
	lli t,n,res,prev,d;
	g(t);
	while(t--)
	{
		res = 0; prev = 0;
		g(n);
		f(i,n)
		{
			g(d);
			if(prev>=0)
				res += prev;
			else
				res -= prev;
			prev += d;
		}
		printf("%lld\n",res);
	}
	return 0;
}