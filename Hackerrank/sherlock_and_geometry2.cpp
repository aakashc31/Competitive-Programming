#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,float> pff;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

bool parametric_intersection(int r, int xc, int yc, int x0, int y0, int x1, int y1)
{
	// printf("For %d,%d -> %d,%d\n",x0,y0,x1,y1);
	float xd = x1-x0, yd = y1-y0;
	float A = xd*xd + yd*yd;
	float B = 2*(xd*(x0-xc) + yd*(y0-yc));
	float C = (x0-xc)*(x0-xc) + (y0-yc)*(y0-yc) - r*r;
	float D = B*B - 4*A*C;
	if(D<0)
		return false;
	// printf("A = %f, B = %f, C = %f\n",A,B,C);
	float disc = sqrt(D);
	// printf("Disc = %f\n",disc);
	float t1 = (-B-disc)/(2*A), t2 = (-B+disc)/(2*A);
	// printf("t1 = %f, t2 = %f\n",t1,t2);
	if((t1>=0 && t1<=1) || (t2>=0 && t2<=1))
	{
		// printf("Returning true for r = %d, xc = %d, yc = %d, x0 = %d, y0 = %d, x1 = %d, y1 = %d\n",r,xc,yc,x0,y0,x1,y1);
		// printf("t1 = %f, t2 = %f\n",t1,t2);
		return true; 
	}
	return false;
}

int main()
{
	int t,r,xc,yc,xi,yi;
	pii ar[3];
	g(t);
	while(t--)
	{
		g(xc),g(yc),g(r);
		f(i,3)
		{
			g(xi) ,g(yi);
			ar[i] = make_pair(xi,yi);
		}
		bool flag = false;

		int i=0, j=1;
		flag = flag||(parametric_intersection(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
			
		i=1, j=2;
		flag = flag||(parametric_intersection(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
		
		i=2,j=0;
		flag = flag||(parametric_intersection(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
		
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}