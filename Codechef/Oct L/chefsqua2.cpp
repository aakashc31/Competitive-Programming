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
		bool fl3 = false, fl4 = false;
		pii prob3, prob4;
		int x1,x2,y1,y2;
		f(i,n)
		{
			fab(j,i+1,n-1)
			{
				x1 = pts[i].first, y1 = pts[i].second, x2 = pts[j].first, y2 = pts[j].second;
				prob3 = mp(x2 + y2 - y1, y2 + x1 - x2);
				prob4 = mp(x1 + y2 - y1, y1 + x1 - x2);
				if(binary_search(pts,pts+numpts,prob3,comp))
				{
					fl3 = true;
					if(binary_search(pts,pts+numpts,prob4,comp))
					{
						fl4 = true;
						break;
					}
				}
				prob3 = mp(x2 - y2 + y1, y2 - x1 + x2);
				prob4 = mp(x1 - y2 + y1, y1 - x1 + x2);
				if(binary_search(pts,pts+numpts,prob3,comp))
				{
					fl3 = true;
					if(binary_search(pts,pts+numpts,prob4,comp))
					{
						fl4 = true;
						break;
					}
				}
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