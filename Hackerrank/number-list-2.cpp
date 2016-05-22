#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int maxn = 200010;
int a[maxn];

void compute(int& n, int& k){
	ll len = 0, ans = 0;
	for(int i=0; i<n;i++){
		if(a[i] > k){
			ans += (len*(len+1))/2;
			len = 0;
		}
		else
			len++;
	}
	ans += (len*(len+1))/2;
	ans = (n*1ll*(n+1))/2 - ans;
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n,k; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0; i<n; i++)
			cin >> a[i];
		compute(n,k);
	}
	return 0;
}