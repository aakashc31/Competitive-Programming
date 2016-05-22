#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

map<pii,bool> M;

bool game(int n, int m){
	if(n == 1 && m == 1)
		return false; //you have lost
	if((n == 1 && m <= 3) || (m==1 && n <= 4))
		return true;
	map<pii,bool>::iterator it = M.find(mp(n,m));
	if(it != M.end())
		return it->second;
	bool flag = true;
	for(int i=1; i<=3; i++){
		if(n-i > 0 && !game(n-i,m)){
			M[mp(n,m)] = true;
			return true;
		}
	}
	for(int j=1; j<=2; j++){
		if(m-j > 0 && !game(n,m-j)){
			M[mp(n,m)] = true;
			return true;
		}
	}
	M[mp(n,m)] = false;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n,m; cin >> t;
	while(t--){
		for(int i = 1; i<=8; i++){
			for(int j=1; j<=8; j++){
				if(game(i,j))
					cout << "Tuzik  ";
				else
					cout << "Vanya ";
			}
			cout << endl;
		}
		// cin >> n >> m;
		// if(game(n,m))
		// 	cout << "Tuzik" << endl;
		// else
		// 	cout << "Vanya" << endl;
	}
	return 0;
}