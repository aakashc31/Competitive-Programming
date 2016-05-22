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

inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

ll dp[500001];
unordered_set<ll> S;

void pre(){
	dp[0] = 0;
	ll curr;
	for(int i=1; i<=500000; i++){
		curr = dp[i-1] - i;
		if(curr > 0 && (S.count(curr) == 0)){
			dp[i] = curr;
			S.insert(curr);
		}			
		else{
			dp[i] = dp[i-1] + i;
			S.insert(dp[i]);
		}
	}
}

int main(){
	pre();
	int n = inp();
	while(n != -1){
		printf("%lld\n", dp[n]);
		n = inp();
	}
	return 0;
}