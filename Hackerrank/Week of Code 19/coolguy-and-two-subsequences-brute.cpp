#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair


int main(){
	int n; cin >> n; 
	vi v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	ll ans = 0; ll modulo = 1e9 + 7;
	int x,y;
	for(int a = 0; a<n; a++){
		for(int b = a; b<n; b++){
			x = *min_element(v.begin()+a, v.begin()+b+1);
			for(int c = b+1; c <n; c++){
				for(int d=c; d < n; d++){
					y = *min_element(v.begin()+c, v.begin()+d+1);
					ans = ans + min(x,y);
					ans %= modulo;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}