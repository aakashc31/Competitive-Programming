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

int dp[2005][2005];
int a[2005];

int main(){
	int t = inp();
	while(t--){
		int n,k;
		n = inp(); k = inp();
		f(i,n) a[i] = inp();
		f(i,k+1) dp[0][i] = (i/a[0]) * a[0];
		for(int i=1; i<n; i++){
			dp[i][0] = 0;
			for(int w = 1; w <= k; w++){
				dp[i][w] = dp[i-1][w];
				int maxCount = w / a[i];
				for(int c = 1; c <= maxCount; c++){
					dp[i][w] = max(dp[i][w], dp[i-1][w - c * a[i]] + c * a[i]);
				}
			}
		}
		cout << dp[n-1][k] << endl;
	}
	return 0;
}