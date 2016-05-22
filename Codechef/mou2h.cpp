#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)
#define getcx getchar_unlocked
#define g(n) inp(n)//scanf("%lld",&n)
typedef long long int lli;
 
const lli modulo = 1000000009;
lli diff[8000001];
bitset<8000001> visited;
lli ar[1000000];
 
 
inline void inp( lli &n )//fast input function
{
	n=0;
	lli ch=getcx();lli sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
 
lli ind(lli a)
{
	if(a>=0)
		return a;
	else
		return 4000000-a;
}
 
int main()
{
	lli t,n,a,b;
	g(t);
	while(t--)
	{
		g(n);
		g(a);
		f(i,n-1)
		{
			g(b);
			ar[i] = b-a;
			visited[ind(ar[i])] = 0;
			a = b;
			// i must unvisit all the diffrences
		}
		// f(i,n-1)
		// 	printf("%d ",ar[i]);
		// printf("\n");
		//now i have all the consecutive diffs
		lli ans = 0;
		f(i,n-1)
		{
			if(visited[ind(ar[i])])
			{
				lli prev_index = diff[ind(ar[i])];
				if(prev_index==0)
				{
					ans = (2*ans)%modulo;
					diff[ind(ar[i])] = i;
					ar[i] = ans;
					// printf("Vis1: ar[%lld] = %lld\n",i,ans);
				}
				else
				{
					diff[ind(ar[i])] = i;
					//compute new ans and store it!
					lli k = (ans + ((modulo-1)*ar[prev_index-1])%modulo)%modulo;
					// k = ((modulo-1)*k)%modulo;
					ans = (ans + k)%modulo;
					ar[i] = ans;
					// printf("Vis2: ar[%lld] = %lld and k = %lld and prev = %lld and prev_index = %lld\n",i,ans,k,ar[prev_index-1],prev_index);
				}
			}
			else
			{
				diff[ind(ar[i])] = i;
				visited[ind(ar[i])]=1;
				ans = (2*ans+1)%modulo;
				ar[i] = ans;
				// printf("Unvis: ar[%lld] = %lld\n",i,ans);
			}
		}
		printf("%lld\n",ans);
	}
} 