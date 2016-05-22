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

const int MOD = 1000000007;

ll dp[1001][1001];
ll Lcount[1001], Ucount[1001];
// dp[i][j] = number of ways to make (j-1) seq ,i.e., select j spheres using spheres of radius <= i
int main(){
	int n,m,c,a;
	cin >> n >> m >> c;
	f(i,n){
		cin >> a;
		Ucount[a]++;
	}
	f(i,m){
		cin >> a;
		Lcount[a]++;
	}

	// base case
	for(int i=1; i<=1000; i++){
		dp[i][1] = (Lcount[i]*Ucount[i] + dp[i-1][1])%MOD;
	}

	// fill the table
	// dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*freq[i]
	for(int i=1; i<=1000; i++){
		for(int j=2; j<=i; j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*((Lcount[i]*Ucount[i])%MOD))%MOD;
		}
	}

	for(int i=1; i<c; i++){
		cout << dp[1000][i+1] << " ";
	}
	cout << 0 << endl;
	return 0;
}