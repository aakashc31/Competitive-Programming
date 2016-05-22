#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
#define maxn 1000010

int main(){
	int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
	int ans = min(min(0,a+b+c+d), min(a+b+f,a+e+d));
	cout << -1*ans << endl;
	return 0;
}