#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)
#define getcx getchar//_unlocked
#define g(n) inp(n)//scanf("%lld",&n)
typedef long long int lli;

inline void inp(lli &n )//fast input function
{
	n=0;
	lli ch=getcx();lli sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

lli power(lli a, lli p)
{
	if(p==0)
		return 1;
	lli half = power(a,p/2);
	half*=half;
	if(p&1)
		half*=a;
	return half;
}

lli sum_dig(lli a)
{
	lli s=0;
	while(a>0)
	{
		s+=(a%10);
		a/=10;
	}
	return s;
}

int main()
{
	lli a,b,c;
	// g(a),g(b),g(c);
	cin >> a >> b >> c;
	lli ar[100];
	lli s=0;
	for(lli i=1; i<=81; i++)
	{
		lli res = b*power(i,a) + c;
		if(res>=1000000000 || b<=0)
			continue;
		if(sum_dig(res)==i)
			ar[s++]=res;
	}
	printf("%d\n",s);
	if(s==0)
		return 0;
	sort(ar,ar+s);
	f(i,s)
		printf("%d ",ar[i]);
	printf("\n");
	return 0;
}