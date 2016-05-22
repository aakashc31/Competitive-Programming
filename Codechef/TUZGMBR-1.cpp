#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void func(int n, int m){
	bool flag = true;
	int x = n%4, y = m%3; if(y==0) y = 3;
	if(x!=0 && (x==y))
		flag = false;
	if(flag)
		cout << "Tuzik" << endl;
	else
		cout << "Vanya" << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n,m; cin >> t;
	while(t--){
		cin >> n >> m;
		func(n,m);
	}
	return 0;
}