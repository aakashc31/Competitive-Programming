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
char ch[100005];
int main()
{
	int c[26];
	int t;
	g(t);
	test(t)
	{
		int ans = 0;
		scanf("%s", ch);
		f(i,26) c[i] = 0;
		f(i,strlen(ch)) c[ch[i] - 'a']++;
		f(i,26) if(c[i]>0) ans++;
		printf("%d\n",ans);
	}
	return 0;
}