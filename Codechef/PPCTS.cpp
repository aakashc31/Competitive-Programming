#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

vi x,y;
int n,m;
string ch;


int main(){
	ios::sync_with_stdio(false); 
	cin >> n >> m;
	x.resize(n); y.resize(n);
	ll init = 0;
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		init += (ll)abs(x[i]) + (ll)abs(y[i]);
	}
	cin >> ch;
	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	int currx = 0, curry = 0, p , q;
	for(int i=0; i<m; i++){
		if(ch[i] == 'R'){
			p = upper_bound(x.begin(), x.end(), currx) - x.begin();
			q = n - p;
			init = init + p - q;
			currx++;
		}
		else if(ch[i] == 'L'){
			p = upper_bound(x.begin(), x.end(), currx-1) - x.begin();
			q = n - p;
			init = init - p + q;
			currx--;
		}
		else if(ch[i] == 'U'){
			p = upper_bound(y.begin(), y.end(), curry) - y.begin();
			q = n - p;
			init = init + p - q;
			curry++;
		}
		else{
			p = upper_bound(y.begin(), y.end(), curry-1) - y.begin();
			q = n - p;
			init = init - p + q;
			curry--;
		}
		cout << init << endl;
	}
	return 0;
}