#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
#define maxn 1000010

const int MOD = 1e9;

int main(){
	srand(time(NULL));
	// int t = 100;
	int n; cin >> n; cout << n << endl;
	for(int i=0; i<n; i++){
		cout << rand()%MOD << " ";
	}
	cout << endl;
	return 0;
}