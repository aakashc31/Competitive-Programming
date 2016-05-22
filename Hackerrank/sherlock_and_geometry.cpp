#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<float,float> pff;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

pff getmc(int x1, int y1, int x2, int y2)
{
	float delx = x1-x2, dely = y1-y2;
	float m =dely/delx;
	float c = (y1*delx - x1*dely)/(delx);
	return make_pair(m,c);
}

bool isIntersecting(int r, int xc, int yc, float m, float c)
{
	float A,B,C,D;
	A = 1+m*m;
	C = xc*xc + (c-yc)*(c-yc) - r*r;
	B = 2*c - 2*yc - 2*xc + 2*m*c - 2*m*yc;
	D = B*B-4*A*C;
	if(D>=0)
		printf("Returning true for r = %d, xc = %d, yc = %d, m = %f, c = %f\n",r,xc,yc,m,c);
	else
		printf("Returning false for r = %d, xc = %d, yc = %d, m = %f, c = %f\n",r,xc,yc,m,c);
}

bool intersection_with_inf_slope(int r, int xc, int yc, int xp) //line xp
{
	float A,B,C,D;
	A = 1;
	C = yc*yc + (xp-xc)*(xp-xc) - r*r;
	B = -2*yc;
	D = B*B-4*A*C;
	if(D>=0)
		printf("Returning true for r = %d, xc = %d, yc = %d, xp = %d",r,xc,yc,xp);
	else
		printf("Returning false for r = %d, xc = %d, yc = %d, xp = %d\n",r,xc,yc,xp);
}

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