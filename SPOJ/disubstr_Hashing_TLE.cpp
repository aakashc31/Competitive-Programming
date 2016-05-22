#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;

ll power_mod(ll n, ll p, ll modulo)
{
	if(p==0) return 1%modulo;
	ll a = 1, sq=n;
	while(p>0)
	{
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}

ll MOD = 1000000007;
ll p = 99991;
ll inv = 278145035;
ll prefix[1005];
ll pmod[1005];
ll invPmod[1005];

void precompute(){
	for(int i=0; i<1001; i++){
		pmod[i] = power_mod(p,i,MOD);
		invPmod[i] = power_mod(inv, i, MOD);
	}
}


int main(){
	precompute();
	int t; get(t);
	string s;
	set<int> allHash;
	while(t--){
		allHash.clear();
		cin >> s;
		prefix[0] = s[0];
		for(int i=1; i<s.length(); i++){
			prefix[i] = (prefix[i-1] + s[i]*pmod[i])%MOD;
		}
		ll curr = 0;
		for(int i=0; i<s.length(); i++){
			for(int j=i; j<s.length(); j++){
				curr = 0;
				if(i==0)
					curr = prefix[j];
				else
					curr = (MOD + prefix[j] - prefix[i-1]) % MOD;
				curr = (curr * (invPmod[i]))%MOD;
				allHash.insert((int)curr);
			}
		}
		cout << allHash.size() << endl;
	}
	return 0;
}