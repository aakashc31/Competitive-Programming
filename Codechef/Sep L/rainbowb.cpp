#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
const int modulo = 1000000007;
int getNc6(int n)
{
	if(n<6)
		return 0;
	lli r = n;
	r = (r*(r-1));
	r%=modulo;
	r *= (n-2);
	r%=modulo;
	r *= (n-3);
	r%=modulo;
	r *= (n-4);
	r%=modulo;
	r *= (n-5);
	r%=modulo;
	r *= (301388891);
	int ans = r%modulo;
	return ans;
}

int main()
{
	int n;
	g(n);
	int p = (n&1)?(n/2):((n/2)-1);
	printf("%d\n",getNc6(p));
	return 0;
}
