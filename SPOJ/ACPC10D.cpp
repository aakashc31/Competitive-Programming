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

ll ar[100000][3];
ll dp[100000][3];

int main(){
	int n,t=1;
	cin >> n;

	while(n!=0){
		f(i,n){
			f(j,3)
				cin >> ar[i][j];
		}
		dp[0][0] = INT_MAX;
		dp[0][1] = ar[0][1];
		dp[0][2] = ar[0][1] + ar[0][2];
		for(int i=1; i<n; i++){
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + ar[i][0];
			dp[i][1] = min(min(dp[i-1][0], dp[i][0]), min(dp[i-1][1], dp[i-1][2])) + ar[i][1];
			dp[i][2] = min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + ar[i][2];
		}
		cout << t << ". " << dp[n-1][1] << endl;
		t++;
		cin >> n;
	}
}