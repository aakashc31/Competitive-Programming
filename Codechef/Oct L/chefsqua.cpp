#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) scanf("%d",&n)
#define mp make_pair
typedef pair<int,int> pii;
// typedef pair<pii,int> tuple;

pii pts[2000];
pii temp[2000];
struct tuple
{
	int next;
	lli dist;
	pii sl;
}; 
tuple data[2000];

void print(tuple t)
{
	printf("Next = %d, Distance = %lld, slope = (%d,%d)\n",t.next,t.dist,t.sl.first,t.sl.second);
}

lli distance_my(int i, int j)
{
	lli xdif = (pts[i].first - pts[j].first);
	lli ydif = (pts[i].second - pts[j].second);
	return (xdif*xdif + ydif*ydif);
}
pii slope(int i, int j)
{
	int xdif = (pts[i].first - pts[j].first);
	int ydif = (pts[i].second - pts[j].second);
	return mp(xdif,ydif);
}
bool stud_comp(const tuple& a, const tuple& b)
{
	if(a.dist == b.dist)
	{
		pii s1 = a.sl;
		pii s2 = b.sl;
		return s1.first*s2.second > s1.second*s2.first;
	}
	return a.dist < b.dist;
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
	sort(temp,temp+n);
	pts[0]=temp[0];
	int numpts = 1;
	fab(i,1,n-1)
	{
		if(temp[i].first != pts[numpts-1].first || temp[i].second != pts[numpts-1].second)
			pts[numpts++] = mp(temp[i].first,temp[i].second);
	}
	// printf("Points sorted:\n");
	// f(i,numpts)
	// 	printf("%d,%d\n",pts[i].first,pts[i].second);
	// redundant points removed from the array
	if(numpts == 1)
		printf("3\n");
	else if(numpts == 2)
		printf("2\n");
	else
	{
		bool flag3 = false, flag4 = false;
		f(i,numpts-2)
		{
			// printf("\n\n i = %d\n",i);
			int k=0;
			fab(j,i+1,numpts-1)
			{
				tuple t;
				t.next = j;
				t.dist = distance_my(i,j);
				t.sl = slope(i,j);
				data[k++] = t;
			}
			sort(data,data+k,stud_comp);
			// printf("Data after sorting:\n");
			// f(j,k) print(data[j]);
			f(j,k-1)
			{
				// printf("\nFor index %d at tuple\n",j);
				tuple cur = data[j];
				tuple toS;
				toS.dist = data[j].dist;
				toS.sl=  mp(-data[j].sl.second,data[j].sl.first);
				toS.next = -1;
				if(binary_search(data,data+k,toS,stud_comp))
				{
					flag3 = true;
					int index = lower_bound(data,data+k,toS,stud_comp)->next;
					// printf("Found perpendicular :) at index %d\n",index);
					pii expec = mp(pts[cur.next].first + pts[data[index].next].first - pts[i].first,pts[cur.next].second + pts[data[index].next].second - pts[i].second);
					// printf("Expected opposite point = %d,%d\n",expec.first,expec.second);
					if(binary_search(pts,pts+n,expec))
					{
						// printf("Yo! All points found :D\n");
						flag4 = true;
						break;
					}
				}
				else
				{
					// printf("No perp found :(\n");
				}
			}
			if(flag4)
				break;
		}
		if(flag4)
			printf("0\n");
		else if(flag3)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}