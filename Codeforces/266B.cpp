#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pii;
#define g(n) scanf("%lld",&n)
#define f(i,n) for(int i=0 ;i<n; i++)


pii isFactorizable(lli area, lli a, lli b)
{
	for(lli i=1; i*i<=area; i++)
	{
		if(area%i==0)
		{
			lli p = i, q = area/i;
			if(a<=p && b<=q)
			{
				return make_pair(p,q);
			}
		}
	}
	return make_pair(-1,-1);
}

int main()
{
	lli n,a1,b1,a,b;
	g(n),g(a1),g(b1);
	a = min(a1,b1);
	b = max(a1,b1);
	lli area = 6*n;
	if(a*b >= area)
	{
		printf("%lld\n%lld %lld\n",a*b,a,b);
		return 0;
	}
	// if(area%a == 0)
	// {
	// 	printf("%lld\n%lld %lld\n",area,a,area/a);
	// 	return 0;
	// }
	// if(area%b == 0)
	// {
	// 	printf("%lld\n%lld %lld\n",area,b,area/b);
	// 	return 0;
	// }
	lli offset = 0;
	while(true)
	{
		pii p = isFactorizable(area+offset,a,b);
		if(p.first==-1 && p.second==-1)
		{
			offset++;
			continue;
		}
		else
		{
			printf("%lld\n%lld %lld\n",area+offset,p.first,p.second);
			return 0;
		}

	}
	return 0;

}