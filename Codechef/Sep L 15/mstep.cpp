#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define mp make_pair
#define pb push_back

pii ar[2505];

int main(){
	int t;
	int n,a;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n*n; i++){
			cin >> a;
			ar[a] = mp(i/n, i%n);
		}
		ll ans = 0;
		for(int i=1; i<n*n; i++){
			int xdiff = ar[i].first > ar[i+1].first ? (ar[i].first - ar[i+1].first) : (ar[i+1].first - ar[i].first);
			int ydiff = ar[i].second > ar[i+1].second ? (ar[i].second - ar[i+1].second) : (ar[i+1].second - ar[i].second);
			ans += ((ll)xdiff + ydiff);
		}
		cout << ans << endl;
	}
	return 0;
}