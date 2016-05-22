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
typedef vector<vi>		vvi;

const int maxn = 20000000;

char dp[maxn+1];

inline void pre(){
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	for(int i=4; i<=maxn; i++){
		dp[i] = 1+dp[i-1];
		if((~i)&1) dp[i] = min((int)dp[i], 1+dp[(i>>1)]);
		if(i%3==0) dp[i] = min((int)dp[i], 1+dp[i/3]);
	}
}

int main(){
	pre();
	int t,a;
	cin >> t;
	f(i,t){
		cin >> a;
		printf("Case %d: %d\n", i+1, dp[a]);
	}
	return 0;
}