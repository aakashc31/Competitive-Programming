#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(lli i=0;i<n;i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define g(n) scanf("%lld",&n)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef long long int lli;
lli power_mod(lli n, lli p, lli modulo)
{
	if(p==0) return 1%modulo;
	lli a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}

lli compute(lli n)
{
	lli s = sqrt(n);
	bool flag = false; //is perfect square
	if(s*s == n)
		flag = true;
	lli c = 0;
	for(int i=2; i*i<n;i++)
	{
		if(n%i==0)
			c++;
	}
	lli ret = power_mod(n,c,10000);
	double digs = c*log10(n);
	if(flag)
	{
		digs += log10(s);
		ret = (ret * s)%10000;
	}
	lli d = digs+1;
	lli p; if(ret!=0) p = log10(ret); else p=0;
	p++;
	lli z=0;
	if(d==2 || d==3)
		z = d-p;
	else if(d>=4)
		z = 4-p;
	f(i,z) printf("0");
	printf("%lld\n",ret);
}

int main()
{
	lli t,n;
	g(t);
	while(t--)
	{
		g(n);
		compute(n);
	}
	return 0;
}