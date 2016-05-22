#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
#define pb push_back
#define LSOne(n) (n & (-n))


class BIT{
private:
	vi ft;
public:
	BIT(int n){
		ft.resize(n+1, 0);
	}
	int query(int a){
		int sum = 0;
		for(; a > 0; a-=LSOne(a))
			sum += ft[a];
		return sum;
	}
	int query(int a, int b){
		if(a > b) return 0;
		return query(b) - (a==1 ? 0 : query(a-1));
	}
	void update(int k, int v){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] += v;
	}
};

int main(){
	int n,t,s,e; cin >> n >> t;
	vvi graph(n+1); vi par(n+1,-1);
	for(int i=0; i<n-1; i++){
		cin >> s >> e;
		graph[s].pb(e);
		par[e] = s;
	}
	int root = 1;
	while(par[root] != -1) root++;
	// cout << "root = " << root << endl;
	ll ans = 0;
	BIT* b = new BIT(n); b->update(root, 1);
	stack<int> S; S.push(root); vector<bool> visited(n+1,false); visited[root] = true; bool flag; int next, curr, temp;
	while(!S.empty()){
		curr = S.top(); flag = true;
		// cout << "curr = " << curr << endl;
		for(int i=0; i<graph[curr].size(); i++){
			next = graph[curr][i];
			if(visited[next])
				continue;
			// cout << "Unvisited child = " << next << endl;
			flag = false;
			visited[next] = true;
			S.push(next);
			temp = (b->query(max(1, next-t), min(n, next+t)));
			ans += ((ll)temp);
			// cout << "temp = " << temp << endl;
			b->update(next, 1);
			break;
		}
		if(flag){
			// cout << "Popping " << curr << endl;
			S.pop();
			b->update(curr, -1);
		}
	}
	cout << ans << endl;
	return 0;
}