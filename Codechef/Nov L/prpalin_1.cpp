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
char* ch;
int main()
{
	ch = new char[100005];
	int t;
	g(t);
	test(t)
	{
		scanf("%s", ch);
		int l = strlen(ch);
		int i=0, j=l-1, cnt=0;
		bool flag = false;
		while(i<j)
		{
			if(ch[i]==ch[j])
				i++,j--;
			else
			{
				if(ch[i]==ch[j-1])
					cnt++, i++, j-=2;
				else if(ch[j]==ch[i+1])
					cnt++, i+=2, j--;
				else
				{
					flag = true; break;
				}
			}
		}
		if(flag)
			printf("NO\n");
		else if(cnt <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}