#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
string st[110];

void printMove(pii from, pii to){
	// cout << from.first << "," << from.second << " -> " << to.first << "," << to.second << endl; 
	if(from.first == to.first && from.second == to.second)
		return;
	if(from.first < to.first){
		cout << "DOWN" << endl;
		printMove(mp(from.first+1, from.second), to);
	}
	else if(from.first > to.first){
		cout << "UP" << endl;
		printMove(mp(from.first-1, from.second), to);
	}
	else if(from.second < to.second){
		cout << "RIGHT" << endl;
		printMove(mp(from.first, from.second+1), to);
	}
	else{
		cout << "LEFT" << endl;
		printMove(mp(from.first, from.second-1), to);
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	pii bot, prin;
	for(int i=0; i<n; i++){
		cin >> st[i];
		for(int j=0; j<st[i].length(); j++){
			if(st[i][j] == 'm')
				bot = mp(i,j);
			else if(st[i][j] == 'p')
				prin = mp(i,j);
		}
	}
	printMove(bot, prin);
	return 0;
}