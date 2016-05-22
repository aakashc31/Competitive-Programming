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

int dp[2005];
int a[2005];

int main(){
	int t = inp();
	while(t--){
		int n,k;
		n = inp(); k = inp();
		f(i,n) a[i] = inp();
		sort(a, a+n);
		dp[0] = 0;
		for(int j = 1; j <= k; j++){
			dp[j] = 0;
			for(int i=0; i<n; i++){
				if(j < a[i]) break;
				dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}