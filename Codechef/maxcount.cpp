#include <bits/stdc++.h>
using namespace std;
#define g(n) inp(n)
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
 
int main()
{
	int t,n,cnt[10001],a;
	g(t);
	while(t--)
	{
		g(n);
		f(i,10001) cnt[i] = 0;
		int v = 0, c = 0;
		f(i,n){
			g(a);
			cnt[a]++;
			if(cnt[a] > c || (cnt[a]==c && a < v))
				c = cnt[a], v = a;
		}
		
		printf("%d %d\n",v,c);
	}
	return 0;
} 