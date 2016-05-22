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
	ll t,r;
	cin >> t;
	f(i,t){
		cin >> r;
		r = 4*r*r;
		cout << "Case " << i+1 << ": " <<  r << ".25" << endl;
	}
	return 0;
}