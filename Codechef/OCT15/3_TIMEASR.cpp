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

inline void printTime(int h, int m){
	if(h<10)
		cout << "0";
	cout << h << ":";
	if(m<10)
		cout << "0";
	cout << m << endl;
}

int main(){
	int t; double a;
	double delta = 1.0/120.0;
	cin >> t;
	while(t--){
		cin >> a;
		f(h,12){
			f(m,60){
				double currAngle = abs(h*30.0 + m*0.5 - 6.0*m);
				if(currAngle > 180)
					currAngle = 360 - currAngle;
				if(abs(currAngle - a) < delta)
					printTime(h,m);
			}
		}
	}
	return 0;
}