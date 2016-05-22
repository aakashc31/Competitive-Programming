#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0;i<n;i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define g(n) inp(n)
lli absolute(lli a)
{
	if(a<0) return -a;
	return a;
}
#define getcx getchar//_unlocked

inline void inp( lli &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}


lli d[100000];
int main()
{
	lli t,n,dino,village;
	g(t);
	while(t--)
	{
		dino=-1,village=-1;
		g(n);
		f(i,n)
		{
			g(d[i]);
			if(d[i]<0 && dino!=-1)
				dino=i;
			else if(village!=-1)
				village=i;
		}
		lli cost = 0;
		while(true)
		{
			if(d[village]==0)
			{
				while(village<n)
				{
					if(d[village]>0)
						break;
					village++;
				}
				if(village==n)
					break;

			}
			if(d[dino]==0)
			{
				while(dino<n)
				{
					if(d[dino]<0)
						break;
					dino++;
				}
				if(dino==n)
					break;
			}
			// now if dinos are over, then you won't reach here. if you reached here that means ki there are dinos
			if(absolute(d[dino]) <= d[village])
			{
				cost += absolute(d[dino]*(village-dino));
				d[village] += d[dino];
				d[dino]=0;
			}
			else
			{
				cost += d[village]*(absolute(village-dino));
				d[dino] += d[village];
				d[village] = 0;
			}
		}
		// f(i,n) printf("%d ",d[i]);
		// printf("\n");
		printf("%lld\n",cost);
	}
	return 0;
}