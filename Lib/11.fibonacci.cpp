#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0; i<n; i++)
#define MAX 1000000

typedef long long int lli;

const lli mod = 1000000007;

struct matrix
{
	lli a,b,c,d;
};

matrix square(matrix m)
{
	matrix n;
	n.a = ((m.a*m.a)%mod + (m.b*m.c)%mod)%mod;
	n.b = ((m.a*m.b)%mod + (m.b*m.d)%mod)%mod;
	n.c = ((m.a*m.c)%mod + (m.c*m.d)%mod)%mod;
	n.d = ((m.c*m.b)%mod + (m.d*m.d)%mod)%mod;
	return n;
}

matrix multiply(matrix m, matrix n)
{
	matrix r;
	r.a = ((m.a*n.a)%mod + (m.b*n.c)%mod)%mod;
	r.b = ((m.a*n.b)%mod + (m.b*n.d)%mod)%mod;
	r.c = ((m.c*n.a)%mod + (m.d*n.c)%mod)%mod;
	r.d = ((m.c*n.b)%mod + (m.d*n.d)%mod)%mod;
	return r;
}

matrix power_matrix(matrix m, lli p)
{
	if(p==0)
	{
		matrix r;
		r.a = r.d = 1;
		r.b = r.c = 0;
		return r;
	}
	if(p%2==0)
	{
		matrix half = power_matrix(m,p/2);
		half = square(half);
		return half;
	}
	else
	{
		matrix half = power_matrix(m,p/2);
		half = square(half);
		half = multiply(half,m);
		return half;
	}
}

lli fib_mod(lli k)
{
	if(k<=2)
		return 1;
	matrix m;
	m.a = m.b = m.c = 1;
	m.d = 0;
	matrix t = power_matrix(m,k-2);
	lli c = (t.a + t.b)%mod;
	// printf("%lld = %lld\n",k,c );
	return c;
}