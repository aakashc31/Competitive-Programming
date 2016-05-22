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

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

const int MAXSIZE=4;
const lli modulo = 1000000007;

// A is n by c, B is c by r, C stores n by r: the matrix pdt of A and B
void multiply_matrices(lli A[][MAXSIZE], lli B[][MAXSIZE], lli C[][MAXSIZE], lli n, lli c, lli r)
{
	f(i,n)
	{
		f(j,r)
		{
			lli temp=0;
			f(k,c) temp=(temp+A[i][k]*B[k][j])%modulo;
			C[i][j] = temp%modulo;
		}
	}
}

// square the matrix
void square(lli A[][MAXSIZE], lli n)
{
	lli B[n][MAXSIZE];
	f(i,n)
	{
		f(j,n) B[i][j] = A[i][j];
	}
	multiply_matrices(B,B,A,n,n,n);
}

// power of A matrix which is n by n, to the pth power
void power_matrix(lli A[][MAXSIZE], lli n, lli p)
{
	if(p<=1)
		return;
	lli B[n][MAXSIZE];
	f(i,n)
	{
		f(j,n) B[i][j] = A[i][j];
	}
	power_matrix(A,n,p/2);
	square(A,n);
	if(p&1)
	{
		lli C[n][MAXSIZE];
		f(i,n)
		{
			f(j,n) C[i][j] = A[i][j];
		}
		multiply_matrices(B,C,A,n,n,n);
	}
}

lli M[4][4] = {{1,1,0,1}, {1,0,0,0}, {0,1,0,0}, {0,0,0,1}};

lli prefix_sum(lli a)
{
	if(a<0) return 0;
	lli init[4][4] = {{2},{1},{0},{1}};
	lli s1;
	if(a>2)
	{
		lli C[4][4];
		f(i,4){
			f(j,4){
				C[i][j] = M[i][j];
			}
		}
		power_matrix(C,4,a-2);
		lli ans[4][4];
		multiply_matrices(C,init,ans,4,4,1);
		s1 = ans[0][0];
	}
	else
	{
		s1 = init[2-a][0];
	}
	return s1;
}

lli getSum(lli a, lli b)
{
	lli ans = (prefix_sum(b) - prefix_sum(a-1))%modulo;
	if(ans < 0)
		ans += modulo;
	return ans;
}


int main()
{
	int t,a,b;
	g(t);
	while(t--)
	{
		g(a), g(b);
		printf("%lld\n",getSum(a,b));
	}
	return 0;
}