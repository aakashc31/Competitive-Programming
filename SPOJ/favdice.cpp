#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;

// expectation val for collecting n coupons
double solveCouponCollectorProblem(int n){
	double ans = 0, num = n;
	for(int i=1; i<=n; i++){
		ans += (num/i);
	}
	return ans;
}

double ar[1001];

void precompute(){
	for(int i=1; i<=1000; i++)
		ar[i] = solveCouponCollectorProblem(i);
}

int main(){
	precompute();
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		printf("%.2lf\n", ar[n]);
	}
	return 0;
}