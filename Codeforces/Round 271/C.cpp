#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
#define mp make_pair

typedef pair<int,int> pii;


bool dist(pii a, pii b)
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return (dx*dx + dy*dy);
}

bool isSquare(pii a,pii b, pii c, pii d)
{

}

pii rotate(pii p, pii r)
{
	return mp(p.second + r.first - r.second, p.first + r.first + r.second);
}

pii rotate_p(pii p, pii r, int z)
{
	pii ans = p;
	f(i,z)
	{
		ans = rotate(ans,r);
	}
	return ans;
}
int main()
{
	int n;
	int x,y,a,b;
	g(n);
	f(i,n)
	{
		pii ar[4], orgs[4];
		f(j,4)
		{
			g(x),g(y),g(a),g(b);
			ar[j] = mp(x,y);
			orgs[j] = mp(a,b);
		}
		int ans = 100;
		f(p,4)
		{
			f(q,4)
			{
				f(r,4)
				{
					f(s,4)
					{
						pii rots1 = rotate_p(ar[0],orgs[0],p);
						pii rots2 = rotate_p(ar[1],orgs[1],q);
						pii rots3 = rotate_p(ar[2],orgs[2],r);
						pii rots4 = rotate_p(ar[3],orgs[3],s);
						if(isSquare(rots1,rots2,rots2,rots4))
						{
							int s = p+q+r+s;
							if(s < ans)
								ans = s;
						}
					}
				}
			}
		}
		if(ans==100)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
}