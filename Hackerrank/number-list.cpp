#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int maxn = 200010;
int a[maxn]; int rm[maxn], lm[maxn];

//rm[i] is the index of first element to the right of i which is greater than a[i]
//lm[i] is the index of first element to the left of i which is greater than or equal to a[i]

void compute(int& n, int& k){
	stack<int> S;
	for(int i=0; i<n; i++){
		while(!S.empty() && a[S.top()] < a[i]){
			rm[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty())
		rm[S.top()] = n, S.pop();
	for(int i=n-1; i>=0; i--){
		while(!S.empty() && a[S.top()] <= a[i]){
			lm[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty())
		lm[S.top()] = -1, S.pop();
	ll ans = 0;
	for(int i=0; i<n; i++){
		if(a[i] > k)
			ans += (rm[i]-i)*1ll*(i-lm[i]);
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,n,k; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0; i<n; i++)
			cin >> a[i];
		compute(n,k);
	}
	return 0;
}