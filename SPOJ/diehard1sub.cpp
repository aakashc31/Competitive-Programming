#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define AIR 0
#define FIRE 1
#define WATER 2

const int maxh = 1100;
const int maxar = 2000;

int dp[maxh][maxar][3];

int compute(int health, int armour, int place){
	//base case
	if(health <= 0 || armour <= 0)
		return 0;
	if(dp[health][armour][place] != -1){
		// printf("pre : compute(%d,%d,%d) = %d\n",health,armour,place,dp[health][armour][place]);
		return dp[health][armour][place];
	}
	//recurrence
	if(place == AIR){
		dp[health][armour][place] = 1 + max(compute(health-5, armour-10, WATER), compute(health-20, armour+5, FIRE));
	}
	else if(place == FIRE){
		dp[health][armour][place] = 1 + max(compute(health+3, armour+2, AIR), compute(health-5, armour-10, WATER));
	}
	else{
		dp[health][armour][place] = 1 + max(compute(health+2, armour+2, AIR), compute(health-20, armour+5, FIRE));
	}
	// printf("compute(%d,%d,%d) = %d\n",health,armour,place,dp[health][armour][place]);
	return dp[health][armour][place];
}

int main(){
	ios::sync_with_stdio(false);
	int t,health,armour;
	cin >> t;
	while(t--){
		cin >> health >> armour;
		int maxh = (6*health)/5 + 100;
		int maxar = 2*armour;
		for(int h = 1; h <= maxh; h++){
			for(int a = 1; a <= maxar; a++){
				for(int p = 0; p <= 2; p++)
					dp[h][a][p] = -1;
			}
		}
		int ans = max(compute(health+3, armour+2, AIR), compute(health-20,armour+5,FIRE));
		ans = max(compute(health-5, armour-10, WATER), ans);
		cout << ans << endl;
	}
	return 0;
}
