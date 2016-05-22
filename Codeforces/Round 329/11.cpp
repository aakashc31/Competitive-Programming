#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;


bool satis(string& s, char a, char b){
	int x = 0, y = 0;
	f(i,s.size()){
		if(s[i] == a)
			x++;
		else if(s[i] == b)
			y++;
		else
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<string> st(n);
	f(i,n) cin >> st[i];

	vvi ar(26, vi(26, 0));
	int maxVal = 0;
	f(i,26){
		f(j,26){
			f(k,n){
				if(satis(st[k], i+'a', j+'a'))
					ar[i][j] += st[k].length();
			}
			if(ar[i][j] > maxVal){
				maxVal = ar[i][j];
			}
		}
	}
	cout << maxVal << endl;
	return 0;
}