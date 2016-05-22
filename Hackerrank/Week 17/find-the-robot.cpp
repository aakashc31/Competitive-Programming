#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair<int,int> pii;

int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int s = n/4;
		pii ans = mp(-2*s, -2*s);
		int k = 4*s + 1;
		if(n%4 == 1){
			ans.first += k;
		}
		else if(n%4 == 2){
			ans.first += k;
			ans.second += (k+1);
		}
		else if(n%4 == 3){
			ans.first -= 2;
			ans.second += (k+1);
		}
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}