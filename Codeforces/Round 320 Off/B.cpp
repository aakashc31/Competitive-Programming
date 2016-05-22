#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;


int main(){
	int n,a;
	cin >> n;
	vvi v(2*n, vi(0));
	for(int i=1; i<=(2*n-1);i++){
		for(int j = 0; j < i; j++){
			cin >> a;
			v[i].push_back(a);
		}
	}
	v[0].push_back(-1);
	vi pairing(2*n, -1);
	int unpaired = 2*n;
	while(unpaired > 0){
		int nexti = 0, nextj = 0, maxStrength = -1;
		for(int i=1; i<=(2*n-1);i++){
			if(v[i].empty())
				continue;
			for(int j=0; j<i; j++){
				if(v[i][j] > maxStrength && !(v[j].empty())){
					maxStrength = v[i][j];
					nextj = j, nexti = i;
				}
			}
		}
		pairing[nexti] = nextj;
		pairing[nextj] = nexti;
		v[nexti].clear();
		v[nextj].clear();
		unpaired -= 2;
	}

	for(int i=0; i<pairing.size();i++)
		cout << pairing[i] + 1 << " ";
	cout << endl;
	return 0;
}