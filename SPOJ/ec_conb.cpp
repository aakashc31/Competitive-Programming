#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int compute(int n){
	if(n&1) return n;
	int l = 32 - __builtin_clz(n);
	int ans = 0;
	for(int i=0; i<l; i++){
		if(n & (1<<i)){
			ans |= (1<<(l-i-1));
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n; cin >> t;
	while(t--){
		cin >> n;
		cout << compute(n) << endl;
	}
	return 0;
}