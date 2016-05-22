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

// num integral points from (0,0) to (a.first, a.second)
ll countNumPoints(pair<ll,ll> a){
	ll x = abs(a.first), y = abs(a.second);
	if(x == 0)
		return max(0ll, y-1);
	if(y==0)
		return max(0ll,x-1);
	ll k = x/(__gcd(x,y));
	return (x/k)-1;
}



int main(){
	int t;
	ll x[4], y[4];
	ll ans, areaTwice;
	cin >> t;
	while(t--){
		f(i,3) cin >> x[i] >> y[i];
		x[3] = x[0], y[3] = y[0];
		ll bc = 0;
		f(i,3){
			bc += countNumPoints(mp(x[i] - x[i+1], y[i] - y[i+1]));
		}
		bc+=3;
		areaTwice = abs(x[0]*(y[1] - y[2]) + x[1]*(y[2] - y[0]) + x[2]*(y[0] - y[1]));
		// cout << "areaTwice = " << areaTwice << " bc = " << bc <<  endl;
		ans = (areaTwice - bc + 2)/2;
		cout << ans << endl;
	}
}