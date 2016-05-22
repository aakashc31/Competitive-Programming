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


vector<int> v[10];

int main(){
	int n,k,a;
	cin >> n >> k;
	int base = 0, resolved = 0;
	for(int i=0; i<n; i++){
		cin >> a;
		v[a%10].push_back(a);
		base += (a/10);
	}
	int left = 0;
	for(int j = 9; j > 0; j--){
		if(k == 0)
			break;
		if(v[j].empty())
			continue;
		int req = 10 - j;
		int canRound = k / req;
		for(int i=0; i<min((int)v[j].size(), canRound); i++){
			k -= req;
			v[j][i] += req;
			base ++;
			left += (100 - v[j][i]) / 10;
		}
	}

	for(int i = 0; i < v[0].size(); i++)
		left += ((100 - v[0][i])/10);

	base += min(k/10, left);

	cout << base << endl;
	return 0;


}