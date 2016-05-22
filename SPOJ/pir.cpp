#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
#define gd(n) scanf("%lf", &n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

double compute_det(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
	double s = 0;
	s += a*(e*i - f*h);
	s += b*(f*g - d*i);
	s += c*(d*h - e*g);
	return s/6;
}

int main()
{
	int t; double a,b,c,d,e,f,p,q,r,x,y;
	g(t);
	test(t)
	{
		gd(c);gd(b);gd(d);gd(a);gd(e);gd(f);
		y = (a*a - b*b + c*c)/(2*c);
		x = sqrt(a*a - y*y);
		// printf("x = %lf\n",x);
		q = (c*c + e*e - d*d)/(2*c);
		p = (a*a + e*e - f*f - 2*q*y)/(2*x);
		r = sqrt(e*e - q*q - p*p);
		// printf("r = %lf\n",r);
		printf("%.4lf\n",compute_det(-p,-p,x-p,-q,c-q,y-q,-r,-r,-r));
	}
	return 0;
}