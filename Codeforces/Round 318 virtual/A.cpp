#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	cin >> n;
	int m; cin >> m;
	priority_queue<int> pq;
	for(int i=0; i<n-1; i++){
		cin >> a;
		pq.push(a);
	}
	int ans = 0;
	while(m <= pq.top()){
		int curr = pq.top();
		pq.pop();
		ans++;
		m++;	
		curr--;
		pq.push(curr);
	}
	cout << ans << endl;
	return 0;
}