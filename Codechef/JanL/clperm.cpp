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

lli sum2(lli a, lli b)
{
	if(a>b)return 0;
	lli a1 = (a*(a-1))/2;
	lli a2 = (b*(b+1))/2;
	return (a2-a1);
}

int main()
{
	lli t,n,k;
	lli ar[100005];
	gl(t);
	test(t)
	{
		gl(n),gl(k);
		f(i,k) gl(ar[i]);
		if(k==0)
		{
			lli tmp = n;
			lli ss = (n*(n+1))/2;
			if(ss%2 == 0) printf("Chef\n");
			else printf("Mom\n");	
			continue;
		}
		ar[k]=n+1;
		k++;
		sort(ar,ar+k);
		if(ar[0]==1)
			printf("Chef\n");
		else if(ar[0]==2)
			printf("Mom\n");
		else
		{
			int i=1; 
			lli ans= (ar[0]*(ar[0]-1))/2;
			while(i<k)
			{
				ans += (sum2(ar[i-1]+1, ar[i]-1));
				if(ans < ar[i]) break;
				i++;
			}
			if(ans%2 == 0) printf("Chef\n");
			else printf("Mom\n");
			// printf("%lld\n",ans+1);
		}

		
	}
	return 0;
}