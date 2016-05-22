#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair


bool dp(int m, int n){
	if(m<=1 && n<=1)
		return false;
	if(m<=1 || n<=1)
		return true;
	bool ret = (dp(m-1,n) && dp(m-2,n) && dp(m-3,n) && dp(m,n-1) && dp(m,n-2));
	return (!ret);
}

int main(){
	while(1){
		int m,n;
		cin >> m >> n;
		if(dp(m,n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl; 
	}
	return 0;
}