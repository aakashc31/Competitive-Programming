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

ll dp[2][40][40];
int n;
bool isFixed[40];

#define OPEN_BRACE 	0
#define	CLOSE_BRACE 1
#define FIXED 		true

// b  = 0 means '[', b = 1 means ']'
ll compute(int b, int i, int diff){
	if(i >= 2*n){
		if(diff == 0){
			// printf("1 dp[%d][%d][%d] = %d\n", b, i, diff, 1);
			return 1;
		}
		else{
			// printf("2 dp[%d][%d][%d] = %d\n", b, i, diff, 0);
			return 0;
		}
	}
	if(diff < 0) {
		// printf("3 dp[%d][%d][%d] = %d\n", b, i, diff, 0);
		return 0;
	}
	if(dp[b][i][diff] != -1)
		return dp[b][i][diff];
	ll ans = 0;
	if(b == OPEN_BRACE){
		ans = compute(OPEN_BRACE, i+1, diff+1) + compute(CLOSE_BRACE, i+1, diff+1);
	}
	else{
		if(isFixed[i] == FIXED)
			ans = 0;
		else
			ans = compute(OPEN_BRACE, i+1, diff-1) + compute(CLOSE_BRACE, i+1, diff-1);
	}
	dp[b][i][diff] = ans;
	// printf("4 dp[%d][%d][%d] = %d\n", b, i, diff, ans);
	return ans;
}

int main(){
	int d = inp(), k, a;
	while(d--){
		memset(isFixed, 0, 40);
		memset(dp, 0xff, 40*40*2*8);
		n = inp(); k = inp();
		f(i,k){
			a = inp();
			isFixed[a-1] = FIXED;
		}
		cout << compute(OPEN_BRACE, 0, 0)/2 << endl;
	}
	return 0;
}	