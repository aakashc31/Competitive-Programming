#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define test(t) while(t--)
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	int A[100000], B[100000];
	int n,k,t;
	g(t);
	test(t)
	{
		g(n), g(k);
		f(i,n) g(A[i]);
		f(i,n) g(B[i]);
		lli prof = ((lli)(k/A[0]))*B[0];
		for(int i=1; i<n; i++)
		{
			lli temp = ((lli)(k/A[i]))*B[i];
			if(temp>prof) prof = temp;
		}
		printf("%lld\n",prof);
	}
	return 0;
}