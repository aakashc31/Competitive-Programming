#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define maxn 1000010
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

vvi ar;

// v is a sorted array 
// this function returns the maximum occurrences of any element in the array
// S has all the elements which have this maximum frequency
inline int processVector(vi& v, vi& S){
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
	maxLen = max(maxLen, currLen);
	return maxLen;
}

inline int processNum(vi& row, vi& column, vi& rmax, vi& colmax){
	if(row.size() == 0)
		return 0;
	int r = processVector(row, rmax);
	int c = processVector(column, colmax);
	return (r+c);
}

inline bool isValid(vi& rmax, vi& colmax, int num){
	for(int i=0; i<rmax.size();i++){
		for(int j=0; j<colmax.size(); j++){
			if(ar[rmax[i]][colmax[j]] != num)
				return true;
		}
	}
	return false;
}

int main(){
	//ios::sync_with_stdio(false);
	int t,n,m; t = inp();
	while(t--){
		n = inp(); m = inp();
		ar = vvi(n, vi(m,0));
		map<int,int> M; int index = 0;
		bool isCoordComp = (n <= 100 && m <= 100);
		if(!isCoordComp) index = 1000001;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				ar[i][j] = inp();
				if(isCoordComp){
					map<int,int>::iterator it = M.find(ar[i][j]);
					if(it == M.end()){
						M[ar[i][j]] = index;
						ar[i][j] = index;
						index++;
					}
					else{
						ar[i][j] = it->second;
					}
				}
			}
		}
		// cout << "Yolo" << endl;
		vvi row(index); vvi column(index); vvi rmax(index); vvi colmax(index);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				row[ar[i][j]].pb(i);
		} 
		for(int j=0; j<m; j++){
			for(int i=0; i<n; i++){
				column[ar[i][j]].pb(j);
			}
		}
		vi S; //set of integers which have maximum (r+c) value
		int currMax = 0, curr;
		for(int i=0; i<index; i++){
			curr = processNum(row[i], column[i], rmax[i], colmax[i]);
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
			if(isValid(rmax[S[i]], colmax[S[i]], S[i])){
				flag = true;
				break;
			}
		}
		if(!flag)
			currMax--;
		printf("%d\n", currMax);
	}
	return 0;
}