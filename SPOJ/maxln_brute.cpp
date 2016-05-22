
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

int main(){
	int t,radius;
	cin >> t;
	while(t--){
		cin >> radius;
		double ab = 0, ac1, ac2, s1,s2;
		double ans = 0.0;
		while(ab <= 2.0*radius){
			ac1 = computeAC(ab, radius);
			s1 = ab*ab + ac1;
			ans = max(ans, s1);
			ab += 0.01;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}