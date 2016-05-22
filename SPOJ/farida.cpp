#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

ll dp[10000][2];
ll ar[10000];

int main(){
	int t,n;
	cin >> t;
	for(int j=1; j<=t; j++){
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> ar[i];
		dp[0][0] = 0;
		dp[0][1] = ar[0];
		for(int i=1; i<n; i++){
			dp[i][1] = ar[i] + dp[i-1][0];
			dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		}
		cout << "Case " << j << ": " << max(dp[n-1][0], dp[n-1][1]) << endl;
	}
	return 0;
}