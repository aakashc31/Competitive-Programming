#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define gt(n) inp(n)
#define getcx getchar//_unlocked
inline void inp(int &n)//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
int getmax(int a, int b, int c)
{
	return max(a,max(b,c));
}
 
int main()
{
	int t,r,g,b,m;
	int R,G,B,temp;
	gt(t);
	while(t--)
	{
		gt(r),gt(g),gt(b),gt(m);
		gt(R);
		f(i,r-1){
			gt(temp);
			if(temp > R) R = temp;
		}
		gt(G);
		f(i,g-1)
		{
			gt(temp);
			if(temp > G) G = temp;
		}
		gt(B);
		f(i,b-1)
		{
			gt(temp);
			if(temp > B) B = temp;
		}
		int ans = getmax(R,G,B);
		f(i,m)
		{
			if(R >= G)
			{
				if(R >= B) R/=2;
				else B/=2;
			}
			else
			{
				if(G>=B) G/=2;
				else B/=2;
			}
			if(getmax(R,G,B) < ans)
				ans = getmax(R,G,B);
		}
		printf("%d\n",ans);
	}
	return 0;
} 