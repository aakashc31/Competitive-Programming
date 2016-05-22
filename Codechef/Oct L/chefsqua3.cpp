#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
typedef pair<int,int> pii;
// typedef pair<pii,int> tuple;

pii pts[2000];
pii temp[2000];
bool comp(const pii& a, const pii& b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main()
{
	int n,a,b;
	g(n);
	f(i,n)
	{
		g(a),g(b);
		temp[i] = mp(a,b);
	}
	if(n==0)
	{
		printf("4\n");
		return 0;
	}
	sort(temp,temp+n, comp);
	pts[0]=temp[0];
	int numpts = 1;
	fab(i,1,n-1)
	{
		if(temp[i].first != pts[numpts-1].first || temp[i].second != pts[numpts-1].second)
			pts[numpts++] = mp(temp[i].first,temp[i].second);
	}
	if(numpts == 1)
		printf("3\n");
	else if(numpts == 2)
		printf("2\n");
	else
	{
		bool fl3 = false, fl4 = false, p1,p2;
		pii prob3, prob4;
		int x1,x2,y1,y2, px1,px2,py1,py2;
		f(i,n)
		{
			fab(j,i+1,n-1)
			{
				x1 = pts[i].first, y1 = pts[i].second, x2 = pts[j].first, y2 = pts[j].second;
				px1 = x1+x2+y1-y2, py1 = y1+y2+x2-x1, px2 = x1+x2+y2-y1, py2 = y1+y2+x1-x2;
				p1 = false, p2 = false;
				if(px1%2==0 && py1%2 == 0 && binary_search(pts,pts+numpts,mp(px1/2,py1/2)))
					p1=true;
				if(px2%2==0 && py2%2 == 0 && binary_search(pts,pts+numpts,mp(px2/2,py2/2)))
					p2=true;
				if(p1 && p2)
				{
					fl4 = true;
					break;
				}
				else if(!p1 && !p2)
				{

				}
				else
					fl3 = true;
			}
			if(fl4)
				break;
		}

		if(fl4)
			printf("0\n");
		else if(fl3)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}