#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair<int,int> pii;
typedef long long int ll;


pii compute(int steps, int i, int j, int r, int c){
	if(j==0 && (i != r-1)){ //first column
		if(i+steps > r-1){
			return compute(steps - (r-1-i), r-1, 0, r,c);
		}
		return mp(i+steps, 0);
	}

	if(i==r-1 && (j != c-1)){ //last row
		if(j+steps > c-1)
			return compute(steps - (c-1-j), r-1, c-1, r, c);
		return mp(i, j+steps);
	}

	if(j == c-1 && i != 0){ //last column
		if(i - steps < 0)
			return compute(steps - i, 0, c-1, r,c);
		return mp(i-steps, j);
	}
	if(i == 0 && j != 0){ //first row
		if(j-steps < 0)
			return compute(steps - j, i, 0, r, c);
		return mp(i,j-steps);
	}
	return mp(-1,-1);
}

int ar[300][300];
int ans[300][300];

int main(){
	int m,n,R;
	cin >> m >> n >> R;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin >> ar[i][j];
	}
	int r=m, c=n;
	pii upleft = mp(0,0);

	while(r>0 && c>0){
		//iterate on the boundaries
		for(int i=0; i<r; i++){
			int j=0;
			int mod = 2*r + 2*c - 4;
			pii temp = compute(R%mod,i,j,r,c);
			ans[upleft.first + temp.first][upleft.second + temp.second] = ar[upleft.first + i][upleft.second+j];

			j=c-1;
			temp = compute(R%mod,i,j,r,c);
			ans[upleft.first + temp.first][upleft.second + temp.second] = ar[upleft.first + i][upleft.second+j];
		}

		for(int j=0; j<c; j++){
			int i=0;
			int mod = 2*r + 2*c - 4;
			pii temp = compute(R%mod,i,j,r,c);ans[upleft.first + temp.first][upleft.second + temp.second] = ar[upleft.first + i][upleft.second+j];

			i=r-1;
			temp = compute(R%mod,i,j,r,c);
			ans[upleft.first + temp.first][upleft.second + temp.second] = ar[upleft.first + i][upleft.second+j];
		}
		upleft.first++;
		upleft.second++;
		r-=2;
		c-=2;
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}