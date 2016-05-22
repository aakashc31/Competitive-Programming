#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair<int,int> pii;
typedef long long int ll;


void precompute(int ar[][1000], int dp[][1000], int r, int c){
	dp[0][0] = ar[0][0];
	for(int i=1; i<c; i++){
		dp[0][i] = dp[0][i-1] + ar[0][i];
	}
	for(int i=1; i<r; i++){
		dp[i][0] = dp[i-1][0] + ar[i][0];
	}
	for(int i=1; i<r; i++){
		for(int j=1; j<c; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + ar[i][j];
		}
	}
}

int ar[1000][1000];
int patt[1000][1000];
int dp[1000][1000];

bool checkMatch(int ar[][1000], int i, int j, int patt[][1000], int r, int c){
	for(int p=0; p<r; p++){
		for(int q=0; q<c; q++){
			if(ar[i+p][j+q] != patt[p][q]){
				return false;
			}
		}
	}
	return true;
}

// i1, j1 is upper left and i2,j2 is lower right 
int getRectangleSum(int dp[][1000], int i1, int j1, int i2, int j2){
	if(i1 == 0 && j1 == 0){
		return dp[i2][j2];
	}
	if(i1 == 0){
		return dp[i2][j2] - dp[i2][j1-1];
	}
	if(j1 == 0){
		return dp[i2][j2] - dp[i1-1][j2];
	}
	return dp[i2][j2] + dp[i1-1][j1-1] - dp[i1-1][j2] - dp[i2][j1-1];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int R,C,r,c;
		cin >> R >> C;
		char ch;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				cin >> ch;
				ar[i][j] = ch-'0';
			}
		}
		cin >> r >> c;
		int pattSum = 0;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin >> ch;
				patt[i][j] = ch-'0';
				pattSum += patt[i][j];
			}
		}

		precompute(ar, dp, R, C);
		bool flag = false;
		for(int i=0; i<=R-r; i++){
			for(int j=0; j<=C-c; j++){
				if(pattSum == getRectangleSum(dp, i,j, i+r-1, j+c-1)){
					if(checkMatch(ar, i,j, patt, r,c)){
						flag = true;
						goto outer;
					}
				}
				// else{
				// 	cout << "pattSum = " << pattSum << " rec sum = " << getRectangleSum(dp,i,j,i+r-1,j+c-1) << endl;
				// }
			}
		}
		outer:
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

