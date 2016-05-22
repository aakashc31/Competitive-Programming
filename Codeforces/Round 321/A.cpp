#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;
typedef long long int ll;
int ar[100005];
int dp[100005];
int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	dp[0] = 1;
	int ans = 1;
	for(int i=1; i<n; i++){
		if(ar[i] >= ar[i-1])
			dp[i] = dp[i-1]+1;
		else
			dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}