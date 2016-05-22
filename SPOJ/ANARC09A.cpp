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

char ch[2005];

int main()
{
	
	int t = 1, l, ans=0;
	while(true)
	{
		scanf("%s",ch);
		// printf("Input = %s\n", ch);
		stack<int> s;
		if(ch[0]=='-')
			break;
		l = strlen(ch);
		ans = 0;
		f(i,l)
		{
			// printf("%d -> %c", i,ch[i]);
			if(ch[i]=='{')
				s.push(1);
			else if(ch[i]=='}')
			{
				if(!s.empty())
					s.pop();
				else
					ans++, s.push(1);
			}
		}
		// printf("ans = %d\n",ans);
		ans += (s.size()/2);
		// printf("stack size = %d\n", s.size());
		printf("%d. %d\n",t,ans);
		t++;
		getchar();
	}
	return 0;
}