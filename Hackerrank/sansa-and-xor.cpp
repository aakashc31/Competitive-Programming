#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			ll count = (ll)(i+1) * (n-i);
			ans ^= (count&1) ? a : 0;
		}
		cout << ans << endl;
	}
	return 0;
}