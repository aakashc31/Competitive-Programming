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
	int t; cin >> t;
	while(t--){
		int a,b; cin >> a >> b;
		if(a<0 && b<0) a=-a, b=-b;
		int o1 = max(a,b), o2 = min(a,b);
		cout << (o1 - o2) / (__gcd(o1 - o2, o1)) << endl;
	}
	return 0;
}