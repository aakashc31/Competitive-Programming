#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 1e6 + 100, mod = 1e9 + 7;
int a[maxn], dp[maxn][2], p[maxn];
ll l, c;
int n, k;
ll ans;
int last;
inline void calc(int i, int j){
	ll t = (c - j + 1LL) % mod;
	if(i > last && l % (ll)n)
		t = (t - 1LL + mod) % mod;
	ll x = (1LL * t * (ll)dp[i][j & 1]) % mod;
	ans = (ans + x) % mod;
}
int main(){
	scanf("%d %lld %d", &n, &l, &k);
	c = l / (ll)n;
	last = ((ll)(l - 1LL) % (ll)n);
	if(l % n)
		++ c;
	k = (int)min((ll)k, c);
	For(i,0,n){
		scanf("%d", a + i);
		p[i] = i;
		dp[i][1] = 1;
		calc(i, 1);
	}
	sort(p, p + n, [](const int &i, const int &j){return pii(a[i], i) < pii(a[j], j);});
	int po = 0;
	For(j,2,k + 1){
		po = 0;
		int x = j & 1, y = !x;
		int sum = 0;
		For(iii,0,n){
			int i = p[iii];
			while(po < n && a[p[po]] <= a[i])
				sum = (sum + dp[p[po ++]][y]) % mod;
			dp[i][x] = sum;
			calc(i, j);
		}
	}
	ans %= mod;
	ans = (ans + mod) % mod;
	printf("%d\n", (int)ans);
	return 0;
}