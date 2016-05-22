#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false);
	int n,q,d; cin >> n >> q;
	vi a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	while(q--){
		cin >> d;
		int ans = (1<<29);
		deque<int> dq;
		for(int i=0; i<n; i++){
			while(dq.size() && a[dq.back()] < a[i])
				dq.pop_back();
			dq.push_back(i);
			while(dq.size() && dq.front() <= i-d)
				dq.pop_front();
			if(i>=d-1)
				ans = min(ans, a[dq.front()]);
		}
		cout << ans << endl;
	}
	return 0;
}

/*Invariant: After i'th iteration, the dq contains i'th element at the back.
The dq has numbers in increasing sequence from back to front. And no number has index  <= i-d, the d-window */