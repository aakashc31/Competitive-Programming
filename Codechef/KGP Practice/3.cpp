#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
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
typedef pair<double, double> pdd;

pdd ar[100000];
pdd ysort[100000];
int n;
pdd fuckpoints[100000];
pdd motherfucker[100000];
int fsize, msize;
bool comp(const pdd& x,const pdd& y)
{
	return x.second < y.second;
}

bool comparator(const pdd& x, const pdd& y)
{
	double dif = x.first - y.first;
	if(dif < 0.00000001 && dif > -0.00000001)
		return x.second < y.second;
	return x.first < y.first;
}

double mydistance(int i, int j)
{
	double xdif = ar[i].first - ar[j].first;
	double ydif = ar[i].second - ar[j].second;
	return sqrt(xdif*xdif + ydif*ydif);
}

double distance_euc(pdd i, pdd j)
{
	double xdif = i.first - j.first;
	double ydif = i.second - j.second;
	return sqrt(xdif*xdif + ydif*ydif);
}

double minTriangle(pdd* ar, int i, int j)
{
	int numPts = j-i+1;
	if(numPts < 3)
		return DBL_MAX;
	if(numPts == 3)
		return mydistance(i,i+1) + mydistance(i,i+2) + mydistance(i+1,i+2);
	int mid = i + (j-i)/2;
	double left = minTriangle(ar, i, mid);
	double right = minTriangle(ar, mid+1, j);
	double d = min(left,right);
	double median = ar[mid].first;
	
	fsize = 0;
	f(q,n)
	{
		if(ysort[q].first >= (median - d/2) && ysort[q].first <= (median + d/2))
			fuckpoints[fsize++] = (ar[q]);
	}
	// printf("Size of fuckpoints = %d\n",fuckpoints.size());
	f(q, fsize)
	{
		msize = 0; //points within range from qth point
		int loda = 0;
		fab(r,q+1,fsize-1)
		{
			if(distance_euc(fuckpoints[q], fuckpoints[r]) > d/2 || (loda > 10))
				break;
			// printf("%d\n",r);
			motherfucker[msize++] = (fuckpoints[r]);
			loda++;
		}
		// printf("Size of motherfucker = %d\n",motherfucker.size());
		// f(r,msize)
		// {
		// 	fab(s,r+1,msize-1)
		// 	{
		// 		double peri = distance_euc(fuckpoints[q], motherfucker[r]) + distance_euc(fuckpoints[q], motherfucker[s]) + distance_euc(motherfucker[r], motherfucker[s]);
		// 		if(peri < d)
		// 		{
		// 			d = peri;
		// 		}
		// 	}
		// }
	}
	return d;

}

int main()
{
	int t;
	double x,y;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n)
		{
			scanf("%lf",&x);
			scanf("%lf",&y);
			ar[i] = mp(x,y);
			ysort[i] = mp(x,y);
		}
		sort(ar, ar+n);
		sort(ysort, ysort+n, comp);
		printf("%.9lf\n",minTriangle(ar,0,n-1));

	}
	return 0;
}