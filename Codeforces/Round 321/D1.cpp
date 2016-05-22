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

int ar[20]; //satisfaction

int rules[20][20];

ll dp[1048576][20];
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	int x,y,c;
	for(int i=0; i<k; i++){
		cin >> x >> y >> c;
		x--; y--;
		rules[x][y] = c;
	}

	//dp[mask][i] = max satisfaction obtained from subset defined by mask, whose last element is i

	for(int mask = 0; mask < (1<<n); mask++){
		for(int i=0; i<n; i++){
			if(mask & (1<<i))
				continue;
			int newMask = mask | (1<<i); 
			if(mask == 0){
				dp[newMask][i] = ar[i];
			}
			else{
				for(int j=0; j<n; j++){
					if(!(mask & (1<<j)))
						continue;
					dp[newMask][i] = max(dp[newMask][i], dp[mask][j] + ar[i] + rules[j][i]);
				}
			}
		}
	}

	ll ans = 0;
	for(int mask = 0; mask < (1<<n); mask++){
		if(__builtin_popcount(mask) != m)
			continue;
		for(int i=0; i<n; i++){
			ans = max(ans, dp[mask][i]);
		}
	}
	cout << ans << endl;

	return 0;
}