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

#define WIN 		1
#define LOSE		2

int k,l;
int dp[1000001]; //dp[i] tells if curr player can win if currently there are i coins

void bottomUp(){
	dp[0] = LOSE;
	for(int n=1; n<=1000000; n++){
		if(dp[n-1] == LOSE) dp[n] = WIN;
		else if(n >= k && dp[n-k] == LOSE) dp[n] = WIN;
		else if(n >= l && dp[n-l] == LOSE) dp[n] = WIN;
		else
			dp[n] = LOSE;
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