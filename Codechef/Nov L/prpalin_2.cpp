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
		bool flag = true;
		while(i<j)
		{
			if(ch[i]==ch[j])
				i++,j--;
			else
				break;
		}
		if(i>=j) printf("YES\n");
		else
		{
			//remove i

			for(int k=i+1, l=j; k<l; k++, l--)
			{
				if(ch[k]!=ch[l])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				printf("YES\n");
				continue;
			}
			for(int k=i, l=j-1; k<l; k++, l--)
			{
				if(ch[k]!=ch[l])
				{
					flag = false;
					break;
				}
			}
			if(flag)
				printf("YES\n");
			else 
				printf("NO\n");

		}
	}
	return 0;
}