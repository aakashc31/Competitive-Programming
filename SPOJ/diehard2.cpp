#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int maxn = 1100;
int dp[maxn][3300][2];

#define WATER 0
#define FIRE 1

int main(){
	int t, health, armour,h2,a2;
	cin >> t;
	while(t--){
		cin >> health >> armour;
		//start from air
		health += 3, armour += 2;
		for(int h = 1; h <= health; h++){
			for(int a = 1; a <= 3*armour; a++){
				for(int p=0; p<=1; p++){
					dp[h][a][p] = 2;
					h2 = h - 2, a2 = a - 8; //p->a->w
					if(h2 > 0 && a2 > 0)
						dp[h][a][p] = max(dp[h][a][p], 2 + dp[h2][a2][WATER]);
					h2 = h - 17, a2 = a + 7;//p->a->f
					if(h2 > 0 && a2 > 0)
						dp[h][a][p] = max(dp[h][a][p], 2 + dp[h2][a2][FIRE]);
					// printf("dp[%d][%d][%d] = %d\n",h,a,p,dp[h][a][p]);
				}
			}
		}
		h2 = health - 5, a2 = armour - 10; //a->w
		int ans1 = 1 + ((h2 <= 0 || a2 <= 0) ? 0 : dp[h2][a2][WATER]);
		h2 = health - 20, a2 = armour + 5;
		int ans2 = 1 + ((h2 <= 0 || a2 <= 0) ? 0 : dp[h2][a2][FIRE]);
		cout << max(ans2, ans1) << endl;
	}
	return 0;	
}