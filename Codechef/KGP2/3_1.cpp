#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%lld",&n)
// #define g(n) inp(n)
// #define gl(n) scanf("%lld", &n)
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

lli modulo = 1000000007; //prime number input each time by the user
const lli size = 100001;
lli fact[size]; //stores the factorial%modulo of all numbers till modulo
lli ifact[size]; //stores the inverse factorial mod modulo of all numbers till modulo
lli inv[size]; //stors the inverse of all numbers till modulo, mod modulo

void calculate_inverses()
{
	inv[1] = 1;
	lli p = modulo;
	for(lli i=2; i<size; i++)
	{
		inv[i] = ((p - p/i)*(inv[p%i]))%p;
	}
}

void init_fact()
{
	fact[0] = 1;
	for(lli i=1;i<size;i++)
	{
		fact[i] = (fact[i-1]*i)%modulo;
	}
}


void inti_ifact()
{
	ifact[0] = 1;
	ifact[1] = 1;
	for(lli i=2; i<size; i++)
	{
		ifact[i] = (ifact[i-1]*inv[i])%modulo;
		
	}
}

lli ncr_mod(lli n, lli r)
{
	if(n<r)
		return 0;
	lli p = ((fact[n]*ifact[r])%modulo)*ifact[n-r];
	return p%modulo;
}

// sum of r vars is 'n'
lli box(lli n, lli r)
{
	// printf("%lld, %lld = %lld\n",n,r,ncr_mod(n+r-1,r-1));
	return ncr_mod(n+r-1,r-1);
}

int main()
{
	lli ub,lb,i,t,n,k,root;
	lli ans = 0;
	calculate_inverses();
	init_fact();
	inti_ifact();
	g(t);
	while(t--)
	{
		g(n), g(k);
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		root = sqrt(k);
		ub = k, lb = k/2 + 1;
		i = 2;
		ans = box(n, root);
		for(lli i = (k/root); i>1; i--)
		{
			lli x = k/i;
			lli y = k/(i-1);
			ans = ans + ((y-x)*box(n-1,i-1))%modulo;
			ans %= modulo;
		}
		if(ans < 0) ans += modulo;
		printf("%lld\n",ans);
	}
	return 0;
}