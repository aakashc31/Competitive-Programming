#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

inline ll compute(ll n){
	ll x = n, y = n+1;
	if(x&1ll)
		y = y/2;
	else
		x = x/2;
	ll a = x/3, b = x%3, c = y/3, d = y%3;
	ll ans = 3*a*c + a*d + b*c + (b*d)/3;
	return ans;
}

int main(){
	int t = inp();
	while(t--){
		ll n = inp();
		printf("%lld\n", compute(n));
	}
	return 0;
}