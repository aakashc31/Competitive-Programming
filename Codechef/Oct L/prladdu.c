#include <stdio.h>
typedef long long int lli;
#define f(i,n) for(i=0;i<n;i++)
#define fab(i,a,b) for(i=a;i<=b;i++)
#define g(n) n=inp()
#define getcx getchar//_unlocked
inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

int main()
{
	lli t,n,res,prev,d,i;
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