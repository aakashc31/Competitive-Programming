#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0; i<n; i++)
typedef long long int lli;
lli v[8];
#define pb push_back
bool comp(const lli& a,const lli& b)
{
	return a>b;
}

int main()
{
	lli t,n,m,a,k;
	g(t);
	while(t--)
	{
		g(n), g(m); 
		lli s=0;
		f(i,n)
		{
			g(a);
			v[i] = a;
		}
		sort(v, v+n, comp);
		k = 0, s = 0;
		while(s<m && k<n)
		{
			s+=v[k];
			k++;
		}
		if(s>=m)
			printf("%lld\n",k);
		else
			printf("-1\n");
	}
	return 0;
} 