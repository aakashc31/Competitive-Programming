
#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int ll;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int fibs[] = 
		{	1 ,
			2 ,
			3 ,
			5 ,
			8 ,
			13 ,
			21 ,
			34 ,
			55 ,
			89 ,
			144 ,
			233 ,
			377 ,
			610 ,
			987 ,
			1597 ,
			2584 ,
			4181 ,
			6765 ,
			10946 ,
			17711 ,
			28657 ,
			46368 ,
			75025 ,
			121393 ,
			196418 ,
			317811 ,
			514229 ,
			832040 ,
			1346269 ,
			2178309 ,
			3524578 ,
			5702887 ,
			9227465 ,
			14930352 ,
			24157817 ,
			39088169 ,
			63245986 ,
			102334155 ,
			165580141 ,
			267914296 ,
			433494437 ,
			701408733
		};

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

// compute i^p % modulo
lli power_mod(lli i, int p)
{
	lli modulo = 1000000007;
	if(p==0)
		return 1;
	else if(p%2==0)
	{
		lli half = power_mod(i,p/2);
		half = (half*half)%modulo;
		return half;
	}
	else
	{
		lli half = power_mod(i,p/2);
		half = (half*half)%modulo;
		half = (half*i)%modulo;
		return half;
	}
}



int findNthNonFibNumber(int n)
{
	int s = 0;
	int i=0; //size = 43
	while(i<42)
	{
		int cnt =  (fibs[i+1] - fibs[i] - 1);
		if(s+cnt >= n)
		{
			return fibs[i] + (n-s);
		}
		else
			s+=cnt;
		i++;
	}
	return fibs[42] + (n-s);
}


int main()
{
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		lli b = fib_mod(n);
		// cout << "b = " << b << endl;
		lli a = findNthNonFibNumber(n);
		// cout << "a = " << a << endl;
		lli ans = power_mod(a,(int)b);
		cout << ans << endl;
	}
	return 0;
}