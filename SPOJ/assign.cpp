#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


ll dp[1<<20][25];
int n;
bool like[20][20];

//dp[mask][i] = number of ways of allotting topics from i to n-1 to people not yet allotted topics in mask

ll compute(int mask, int i){
	if(i == n){
		if(mask == ((1<<n)-1)){
			return 1;
		}
		return 0;
	}

	if(dp[mask][i] != -1)
		return dp[mask][i];

	ll ans = 0;
	for(int j=0; j<n; j++){
		if(mask & (1<<j))
			continue;
		if(!like[j][i])
			continue;
		ans += compute(mask | (1<<j), i+1);
	}
	dp[mask][i] = ans;
	return ans;
}


int main(){
	int c,a;
	cin >> c;
	while(c--){
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> a;
				like[i][j] = false;
				if(a==1)
					like[i][j] = true;
			}
		}

		for(int i=0; i<(1<<n); i++){
			for(int j=0; j<n; j++){
				dp[i][j] = -1;
			}
		}

		cout << compute(0,0) << endl;
	}
	return 0;
}