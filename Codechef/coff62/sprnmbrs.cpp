#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;
typedef long long int ll;

ll compute2(ll n){
	ll ret = 0;
	while(n>0){
		n/=3;
		ret++;
	}
	return ret;
}

ll compute(ll n){
	ll pow2 = 2; 
	ll ret = 0;
	while(pow2 <= n){
		//pow2 * (3^y) such that it is less than n
		ret += compute2(n/pow2);
		pow2 = (pow2<<1);
	}
	return ret;
}

int main(){
	int t;
	ll l,r;
	cin >> t;
	while(t--){
		cin >> l >> r;
		ll ans = compute(r) - compute(l-1);
		if(l<=1) ans++;
		cout <<  ans << endl;
	}
	return 0;
}