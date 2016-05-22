#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)
#define getcx getchar//_unlocked
#define g(n) inp(n)//scanf("%lld",&n)
typedef long long int lli;
const int MAXSIZE=10;
// A is n by c, B is c by r, C stores n by r: the matrix pdt of A and B
void multiply_matrices(int A[][MAXSIZE], int B[][MAXSIZE], int C[][MAXSIZE], int n, int c, int r)
{
	f(i,n)
	{
		f(j,r)
		{
			int temp=0;
			f(k,c) temp+=A[i][k]*B[k][j];
			C[i][j] = temp;
		}
	}
}

// square the matrix
void square(int A[][MAXSIZE], int n)
{
	int B[n][MAXSIZE];
	f(i,n)
	{
		f(j,n) B[i][j] = A[i][j];
	}
	multiply_matrices(B,B,A,n,n,n);
}

// power of A matrix which is n by n, to the pth power
void power_matrix(int A[][MAXSIZE], int n, int p)
{
	if(p==0)
		return;
	int B[n][MAXSIZE];
	f(i,n)
	{
		f(j,n) B[i][j] = A[i][j];
	}
	power_matrix(A,n,p/2);
	square(A,n);
	if(p&1)
	{
		int C[n][MAXSIZE];
		f(i,n)
		{
			f(j,n) C[i][j] = A[i][j];
		}
		multiply_matrices(B,C,A,n,n,n);
	}
}

int main()
{
	printf("A\n");
	return 0;
}
