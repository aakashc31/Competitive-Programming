#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int maxn = 100010;
const int maxlog = 20;

int M[maxn][maxlog];

void precompute(vi& v){
	int n = v.size();
	for(int i=0; i<n; i++)
		M[i][0] = i;
	for(int j=1; (1<<j) <= n; j++){
		for(int i=0; (i + (1<<(j-1))) < n; i++){
			if(v[M[i][j-1]] > v[M[i+(1<<(j-1))][j-1]])
				M[i][j] = M[i][j-1];
			else
				M[i][j] = M[i+(1<<(j-1))][j-1];
		}
	}
}

//R max query
inline int RMQ(vi& v, int i, int j){
	int k = j-i;
	k = 31 - __builtin_clz(k+1);
	return max(v[M[i][k]],v[M[j-(1<<k)+1][k]]);
}

int main(){
	ios::sync_with_stdio(false);
	int n,q,d; cin >> n >> q; vi v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	precompute(v);
	while(q--){
		cin >> d;
		int ans = RMQ(v,0,d-1);
		for(int i=1; i<=n-d; i++)
			ans = min(ans, RMQ(v,i,i+d-1));
		cout << ans << endl;
	}
	return 0;
}