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


int main()
{
	char ch[110][110];
	char ans[110][110];
	int n;
	g(n);
	f(i,n)
	{
		scanf("%s", ch[i]);
	}
	f(i,n)
	{
		f(j,n)
		{
			if(i==0 || i==n-1 || j==0 || j==n-1)
				ans[i][j] = ch[i][j];
			else if(ch[i][j] > ch[i-1][j] && ch[i][j] > ch[i+1][j] && ch[i][j] > ch[i][j+1] && ch[i][j] > ch[i][j-1])
				ans[i][j] = 'X';
			else
				ans[i][j] = ch[i][j];
		}
		ans[i][n] = '\0';
	}

	f(i,n)
		printf("%s\n", ans[i]);
	return 0;
}