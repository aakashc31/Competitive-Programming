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


char A[2005], B[2005];
int a[26], b[26];
int main()
{
	while(cin >> A)
	{
		cin >> B;
		f(i,26) a[i] = 0, b[i] = 0;
		f(i,strlen(A)) a[A[i]-'a']++;
		f(i,strlen(B)) b[B[i]-'a']++;
		f(i,26)
		{
			f(j,min(a[i],b[i]))
				printf("%c",'a'+i);
		}	
		printf("\n");
	}
	return 0;
}