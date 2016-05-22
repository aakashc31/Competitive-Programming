#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;
bool cmp(const int& a, const int& b){
	return b<a;
}

const ll modulo = 1000000007;

// compute i^p % modulo
ll power_mod(ll i, int p)
{
	if(p==0)
		return 1;
	else if(p%2==0)
	{
		ll half = power_mod(i,p/2);
		half = (half*half)%modulo;
		return half;
	}
	else
	{
		ll half = power_mod(i,p/2);
		half = (half*half*i)%modulo;
		return half;
	}
}

int main(){
	int t,n;
	int ar[100000];
	cin >> t;
	test(t){
		cin >> n;
		f(i,n) cin >> ar[i];
		sort(ar, ar+n, cmp);
		ll ans = 0;
		f(i,n){
			// a[i] * (2**(n-1-i) - 2**i)
			ll m1 = (ar[i]*power_mod(2,n-1-i))%modulo;
			ll m2 = (ar[i]*((power_mod(2,i)*(modulo-1))%modulo))%modulo;
			ans += (m1+m2)%modulo;
			ans %= modulo;
		}
		cout << ans << endl;
	}
	return 0;
}