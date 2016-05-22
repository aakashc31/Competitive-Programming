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

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

#define PLAYER_1 	0
#define PLAYER_2 	1

#define UNINIT		0
#define WIN 		1
#define LOSE		2

int k,l;

int dp[1000001]; //dp[i] tells if curr player can win if currently there are i coins

// top-down memoization
// int compute(int n, int player){
// 	if(dp[n][player] != UNINIT)
// 		return dp[n][player];
// 	if(n <= max(1, max(k,l)))
// 		return WIN;
// 	//either take 1 or k or l
// 	int move1 = compute(n-1, player^1);
// 	int move2 = compute(n-l, player^1);
// 	int move3 = compute(n-k, player^1);
// 	int sum = move3 + move2 + move1;
// 	if(sum == 3){
// 		//opponent wins in all three cases
// 		dp[n][player] = LOSE;
// 		return LOSE;
// 	}
// 	else{
// 		dp[n][player] = WIN;
// 		return WIN;
// 	}
// }


void bottomUp(){
	for(int n=1; n<=1000000; n++){
		if(n <= l){
			dp[n] = WIN;
		}
		else{
			int opp = dp[n-1] + dp[n-l] + dp[n-k];
			if(opp == 3)
				dp[n] = LOSE;
			else
				dp[n] = WIN;
		}
	}
}

int main(){
	int m,n,result;
	cin >> k >> l >> m;
	bottomUp();
	string ans = "";
	f(i,m){
		cin >> n;
		result = dp[n];
		if(result == WIN) {
			ans += 'A';
		}
		else {
			ans+='B';
		}
	}
	cout << ans << endl;
	return 0;
}