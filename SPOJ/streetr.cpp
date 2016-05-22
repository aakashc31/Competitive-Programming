#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;
const int maxn = 1e5 + 10;
int ar[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n; int g = 0;
	for(int i=0; i<n; i++){
		cin >> ar[i];
		if(i)
			g = __gcd(g, ar[i] - ar[i-1]);
	}
	int ans = 0;
	for(int i=1; i<n; i++){
		ans += ((ar[i] - ar[i-1])/g - 1);
	}
	cout << ans << endl;
	return 0;
}