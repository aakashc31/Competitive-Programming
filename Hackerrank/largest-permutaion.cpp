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
	int n,k; cin >> n >> k; 
	vi v(n); vi m(n+1);
	for(int i=0; i<n; i++){
		cin >> v[i];
		m[v[i]] = i;
	}
	k = min(k, n-1);
	int ind = 0, val = n;
	while(ind < n-1 && k > 0){
		while(ind < n-1 && v[ind] == val){
			val--, ind++;
		}
		if(ind == n-1)
			break;
		// cout << "ind = " << ind << " val = " << val << " ind_val = " << m[val] << endl;
		v[m[val]] = v[ind];
		m[v[ind]] = m[val];
		m[val] = ind;
		v[ind] = val;
		ind++, val--; k--;
	}
	for(int i=0; i<n; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}