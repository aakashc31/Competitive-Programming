#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx 			getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

string compute(ll n){
	n--;
	string ans(100,'5'); int len=0;
	while(n > 1){
		int x = (63 - __builtin_clzll(n+2));
		ll j = n - (1ll << x) + 3;
		if(j <= (1ll << (x-1))){
			ans[len++] = '5';
			n -= (1ll << (x-1));
		}
		else{
			ans[len++] = '6';
			n -= (1ll << x);
		}
	}
	ans[len++] = (n==0) ? '5' : '6';
	ans.resize(len);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int n; ll k; cin >> n;
	while(n--){
		cin >> k;
		cout << compute(k) << endl;
	}
	return 0;
}