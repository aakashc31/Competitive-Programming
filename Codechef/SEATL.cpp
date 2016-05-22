#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define maxn 1000010

vvi ar;

int maxConsecutive(const vi& v){
	int maxLen = 1, curr = v[0], currLen = 1;
	for(int i=1; i<v.size(); i++){
		if(v[i] == curr){
			currLen++;
		}
		else{
			maxLen = max(maxLen, currLen);
			currLen = 1; curr = v[i];
		}
	}
	maxLen = max(maxLen, currLen);
	return maxLen;
}

int maxSum(const vi& row, const vi& column){
	assert(row.size() == column.size());
	if(row.size() == 0)
		return 0;
	return maxConsecutive(row) + maxConsecutive(column);
}

vi getSetWithElements(const vi& v){
	vi S;
	int maxLen = 1, curr = v[0], currLen = 1;
	for(int i=1; i<v.size(); i++){
		if(v[i] == curr){
			currLen++;
		}
		else{
			if(currLen == maxLen){
				S.pb(curr);
			}
			else if(currLen > maxLen){
				S.clear(); S.pb(curr);
			}
			maxLen = max(maxLen, currLen);
			currLen = 1; curr = v[i];
		}
	}
	if(currLen == maxLen){
		S.pb(curr);
	}
	else if(currLen > maxLen){
		S.clear(); S.pb(curr);
	}
	return S;
}

bool isMaxFrequency(const vi& row, const vi& column, int num){
	vi rmax = getSetWithElements(row);
	vi colmax = getSetWithElements(column);
	for(int i=0; i<rmax.size(); i++){
		for(int j=0; j<colmax.size(); j++){
			if(ar[rmax[i]][colmax[j]] != num)
				return true;
		}
	} 
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n,m; cin >> t;
	while(t--){
		vvi row(maxn); vvi column(maxn);
		cin >> n >> m;
		ar = vvi(n, vi(m,0));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> ar[i][j];
				row[ar[i][j]].pb(i);
			}
		}
		for(int j=0; j<m; j++){
			for(int i=0; i<n; i++){
				column[ar[i][j]].pb(j);
			}
		}
		vi S; //set of integers which have maximum (r+c) value
		int currMax = 0, curr;
		for(int i=1; i<=1000000; i++){
			curr = maxSum(row[i], column[i]);
			if(curr == 0)
				continue;
			if(curr == currMax){
				S.pb(i);
			}
			else if(curr > currMax){
				S.clear(); S.pb(i);
				currMax = curr;
			}
		}
		bool flag = false;
		for(int i=0; i<S.size(); i++){
			if(isMaxFrequency(row[S[i]], column[S[i]], S[i])){
				flag - true;
				break;
			}
		}
		if(!flag)
			currMax--;
		cout << currMax << endl;
	}
	return 0;
}