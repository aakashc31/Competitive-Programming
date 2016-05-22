#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair

int main(){
	ios::sync_with_stdio(false);
	ll n,m,k,x,r,c,sum;
	int t; cin >> t;
	while(t--){
		cin >> n >> m >> k;
		sum = 0;
		double p1 = (n*(n+1))/2;
		double p2 = (m*(m+1))/2;
		double t1,t2,ans=0;
		for(int i=0; i<k; i++){
			cin >> x; x--;
			r = x/m; c = x%m; r++, c++;
			x = r*(n-r+1)*c*(m-c+1);
			t1 = ((double)(r*(n-r+1)))/p1;
			t2 = ((double)(c*(m-c+1)))/p2;
			sum += x;
			ans += (t1*t2);
		}
		ll total = (n*m*(n+1)*(m+1))/4;
		double ans0 = ((double)sum) / ((double)total);
		printf("%.9lf\n", ans);
		printf("%.9lf\n", ans0);
	}
	return 0;
}