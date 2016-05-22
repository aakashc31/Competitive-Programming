#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)

lli get_count(lli a, lli b, lli p)
{
	lli q1,r1,q2,r2,ans = 0;
	q1 = a/p, q2 = b/p, r1 = a%p, r2 = b%p;
	lli temp = q2-q1-1;
	if(temp<0) temp=0;
	for(lli i=1; i<p; i++)
	{
		if((i*i*i)%p==1)
		{
			ans += temp;
			if(q1==q2)
			{
				// if(i>=r1 && i<=r2)
				// 	ans++;
			}
			else
			{
				if(i>=r1)
					ans++;
				if(i<=r2)
					ans++;
			}
		}
	}
	return ans;
}

lli brute(lli a, lli b, lli p)
{
	lli ans = 0;
	while(a<=b)
	{
		if((a*a*a)%p==1)
			ans++;
		a++;
	}
	return ans;
}

int main()
{
	lli a,b,p;
	g(a),g(b),g(p);
	printf("%lld\n",get_count(a,b,p));
	// printf("%lld\n",brute(a,b,p));
	return 0;
}