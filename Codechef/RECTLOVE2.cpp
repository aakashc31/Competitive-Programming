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
		double p1 = (n*(n+1))/2;
		double p2 = (m*(m+1))/2; double t1,t2,ans=0;
		for(int i=0; i<k; i++){
			cin >> x; x--;
			r = x/m; c = x%m; r++, c++;
			t1 = ((double)(r*(n-r+1)))/p1;
			t2 = ((double)(c*(m-c+1)))/p2;
			ans += (t1*t2);
		}
		printf("%.9lf\n", ans);
	}
	return 0;
}