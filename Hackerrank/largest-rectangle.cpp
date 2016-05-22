#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define maxn 100005
int ar[maxn], ridx[maxn], lidx[maxn];
int n;

void computeLeftAndRightVals(){
	stack<int> S; S.push(0);
	for(int i=1; i<n; i++){
		while(!S.empty() && ar[S.top()] > ar[i]){
			ridx[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty()){
		ridx[S.top()] = n;
		S.pop();
	}

	S.push(n-1);
	for(int i=n-2; i>=0; i--){
		while(!S.empty() && ar[S.top()] > ar[i]){
			lidx[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty()){
		lidx[S.top()] = -1;
		S.pop();
	}
}

ll computeMaxAreaRectangle(){
	ll ans = 0;
	for(int i=0; i<n; i++){
		ll span = ridx[i] - lidx[i] - 1;
		ans = max(ans, span * ar[i]);
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	computeLeftAndRightVals();
	cout << computeMaxAreaRectangle() << endl;
	return 0;
}