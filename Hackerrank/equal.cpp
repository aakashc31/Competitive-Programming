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

int ar[10000];
int dp[1000];

inline int compute(int x){
	if(x == 0) return 0;
	int ans = x/5;
	x = x%5;
	ans += (x/2);
	x%=2;
	ans += x;
	return ans;
}

void pre(){
	dp[0] = 0;
	for(int i=1; i<1000; i++){
		dp[i] = 1 + dp[i-1];
		if(i >= 2) dp[i] = min(dp[i], 1 + dp[i-2]);
		if(i >= 5) dp[i] = min(dp[i], 1 + dp[i-5]);
	}
}

int main(){
	// pre();
	int t,n;
	t = inp();
	while(t--){
		n = inp();
		f(i,n) cin >> ar[i];
		sort(ar, ar+n);
		int final = ar[0];
		int ans = 0;
		f(i,n){
			ans += compute(ar[i] - final);
		}
		for(int del = 1; del<=10; del++){
			final = ar[0] - del;
			int temp = 0;
			f(i,n) temp += compute(ar[i] - final);
			ans = min(ans, temp);
		}
		cout << ans << endl;
	}
	return 0;
}