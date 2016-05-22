#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	while(n != 0){
		vector<ll> students(n,0); vector<ll> price(n,0);
		for(int i=0; i<n; i++) cin >> students[i];
		for(int i=0; i<n; i++) cin >> price[i];
		ll ans = 0;
		sort(price.begin(), price.end());
		sort(students.begin(), students.end());
		for(int i=0; i<n; i++) ans += (price[i] * students[n-1-i]);
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}