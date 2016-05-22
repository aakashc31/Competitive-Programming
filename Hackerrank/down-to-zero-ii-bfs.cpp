#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int maxn = 1e6 + 5;
bool visited[maxn];
int main(){
	ios::sync_with_stdio(false);
	int t,n; cin >> t;
	while(t--){
		cin >> n;
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		memset(visited, 0, n);
		queue<int> q; q.push(n);
		visited[n] = true;
		int level = 1, curr;
		while(!q.empty()){
			queue<int> qtemp;
			while(!q.empty()){
				curr = q.front(); q.pop();
				if(!visited[curr-1])
					visited[curr-1] = true, qtemp.push(curr-1);
				for(int i=2; i*i<=curr; i++){
					if(curr % i == 0 && !visited[curr/i])
						visited[curr/i] = true, qtemp.push(curr/i);
				}
			}
			if(visited[0])
				break;
			q = qtemp;
			level++;
		}
		cout << level << endl;
	}
	return 0;
}