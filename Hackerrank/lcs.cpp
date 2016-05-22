#include <bits/stdc++.h>
using namespace std;


int A[100], B[100];
int dp[100][100];
int table[100][100];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> A[i];
	for(int i=0; i<m; i++)
		cin >> B[i];
	dp[0][0] = (A[0] == B[0]) ? 1 : 0;
	for(int i=1; i<m; i++)
		dp[0][i] = (dp[0][i-1] > 0) ? 1 : (A[0] == B[i] ? 1 : 0);
	for(int i=1; i<n; i++)
		dp[i][0] = (dp[i-1][0] > 0) ? 1 : (A[i] == B[0] ? 1 : 0);
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(A[i] == B[j]){
				dp[i][j] = dp[i-1][j-1]+1;
				table[i][j] = 1;
			}
			else if(dp[i-1][j] > dp[i][j-1]){
				dp[i][j] = dp[i-1][j];
				table[i][j] = 2;
			}
			else{
				dp[i][j] = dp[i][j-1];
				table[i][j] = 3;
			}
		}
	}
	int i=n-1, j=m-1, lcs = dp[i][j];
	vector<int> ans(lcs, 0);
	int size = 0;
	while(i>0 && j>0){
		if(A[i] == B[j]){
			ans[lcs-1-size] = A[i];
			i--,j--;
			size++;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	if(dp[i][j] > 0){
		if(j==0)
			ans[0] = B[0];
		else
			ans[0] = A[0];
	}
	for(int i=0; i<lcs; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}