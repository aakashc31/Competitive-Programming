#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define getcx 			getchar//_unlocked
inline ll inp(){
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}
const int maxn = 1010;
int dp[maxn][2];
int a[maxn]; int n;

int main(){
	int t = 1, idx; n = inp();
	int j, right, left, f, inv;
	while(n > 0){
		for(int i=0; i<n; i++)
			a[i] = inp();
		f = 0, inv = 1;
		for(int k=2; k<=n; k+=2){
			for(int i = 0; i < n-k+1; i++){
				j = i+k-1;
				if(k == 2)
					dp[i][f] = max(a[i],a[i+1]) - min(a[i],a[i+1]);
				else{
					left = a[i] - (a[i+1] >= a[j] ? (a[i+1] - dp[i+2][inv]) : (a[j] - dp[i+1][inv]));
					right = a[j] - (a[i] >= a[j-1] ? (a[i] - dp[i+1][inv]) : (a[j-1] - dp[i][inv]));
					dp[i][f] = max(left, right);
				}
			}
			f ^= 1, inv ^= 1;
		}
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, dp[0][inv]);
		n = inp(); t++;
	}
	return 0;
}