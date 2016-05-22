#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

inline double computeAC(double ab, int radius){
	radius = (radius<<1);
	return sqrt(radius*radius - ab*ab);
}

double binarySearch(double low, double high, int radius){
	// printf("binarySearch(%lf, %lf, %d)\n",low,high,radius);
	if(abs(high - low) <= 0.01)
		return high;
	double mid = (low + high)/2;
	double ac_mid = computeAC(mid, radius);
	double ac_left = computeAC(mid - 0.005, radius);
	double ac_right = computeAC(mid + 0.005, radius);
	double smid = mid*mid + ac_mid, sleft = (mid-0.005)*(mid-0.005) + ac_left, sright = (mid+0.005)*(mid+0.005) + ac_right;
	if(smid >= sleft && smid >= sright)
		return mid;
	if(sleft <= smid && smid <= sright)
		return binarySearch(mid+0.005, high, radius);
	else
		return binarySearch(low, mid-0.005, radius);
}

int main(){
	int t,r;
	cin >> t;
	while(t--){
		cin >> r;
		double a = binarySearch(0, 2*r, r);
		double ans =  a*a + computeAC(a,r) ;
		printf("%.2lf\n", ans);
	}
	return 0;
}
