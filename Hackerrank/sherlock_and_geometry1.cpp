#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,float> pff;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)


bool isInside(int r, int xc, int yc, float x0, float y0)
{
	float f1 = (x0-xc)*(x0-xc) + (y0-yc)*(y0-yc) - r*r;
	// printf("Circle: r= %d center = %d,%d, point = %f,%f f1 = %f | ",r,xc,yc,x0,y0,f1);
	if(f1<=0)
	{
		// printf("Returning true\n");
		return true;
	}
	else
	{
		// printf("Returning false\n");
		return false;
	}
}

float absl(float a)
{
	if(a<0) return -a;
	return a;
}

bool rec_line_int(int r, int xc, int yc, float x0, float y0, float x1, float y1)
{
	printf("Yo %f,%f to %f,%f\n",x0,y0,x1,y1);
	bool i1 = isInside(r,xc,yc,x0,y0);
	bool i2 = isInside(r,xc,yc,x1,y1);
	if(i1&&i2) //both points are inside, trivial rejection
		return false;
	if(i1 && !i2) //one inside, one outside, trivial acceptance
		return true;
	if(!i1 && i2) //one inside, one outside, trivial acceptance
		return true;
	if(absl(x0-x1) <= 0.1 && absl(y0-y1) <= 0.01) //the segment is a point, and it is inside.
		return false;
	// if(x0==x1 && y0==y1)
	// 	return false;
	float midx = (x0+x1)/2, midy = (y0+y1)/2;
	return (rec_line_int(r,xc,yc,x0,y0,midx,midy) || rec_line_int(r,xc,yc,midx,midy,x1,y1));
}

int main()
{
	int t,r,xc,yc,xi,yi;
	pff ar[3];
	g(t);
	while(t--)
	{
		g(xc),g(yc),g(r);
		f(i,3)
		{
			g(xi) ,g(yi);
			ar[i] = make_pair(float(xi),float(yi));
		}
		bool flag = false;

		int i=0, j=1;
		flag = flag||(rec_line_int(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
			
		i=1, j=2;
		flag = flag||(rec_line_int(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
		
		i=2,j=0;
		flag = flag||(rec_line_int(r,xc,yc,ar[i].first,ar[i].second,ar[j].first,ar[j].second));
		
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}