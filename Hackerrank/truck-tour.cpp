#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int maxn = 1e5+10;
int d[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, dist, petrol; cin >> n;
	d[0] = 0; bool isNeg = false;
	for(int i=1; i<n; i++){
		cin >> petrol >> dist;
		d[i] = d[i-1] + petrol - dist;
		isNeg = isNeg || (d[i]<0);
	}
	cin >> petrol >> dist;
	d[0] = d[n-1] + petrol - dist;
	isNeg = isNeg || (d[0] < 0);
	if(!isNeg){
		cout << 0 << endl;
		return 0;
	}
	int index=0, val=d[0];
	for(int i=1; i<n; i++){
		if(d[i] < val){
			val = d[i];
			index = i;
		}
	}
	cout << index << endl;
	return 0;
}