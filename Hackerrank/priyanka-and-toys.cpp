#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n; vi v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int start = 0, ans = 0;
	while(start < n){
		int curr = v[start]; int i=0;
		for(i=start; i<n; i++){
			if(v[i] - curr > 4)
				break;
		}
		ans++;
		start = i;
	}
	cout << ans << endl;
	return 0;
}