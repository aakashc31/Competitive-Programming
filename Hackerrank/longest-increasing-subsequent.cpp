#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
const int inf = 10*maxn;

int a[maxn];
int m[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n,l,ans; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i]; m[i+1] = inf;
	}
	m[0] = -1*inf;
	m[1] = a[0], ans = 1;
	for(int i=1; i<n; i++){
		l = lower_bound(m+1, m+n+1, a[i]) - (m+1);
		ans = max(ans, 1+l);
		m[l+1] = min(m[l+1],a[i]);
	}
	cout << ans << endl;
	return 0;
}