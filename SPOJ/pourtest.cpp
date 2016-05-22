#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int a,b,c;
const int maxn = 40010;
bool visited[maxn][maxn];

vector<pii> neighbours(pii p){
	vector<pii> ret; int x = p.first; int y = p.second;
	ret.pb(mp(0,y)); ret.pb(mp(x,0)); //empty any one
	if(y != b) ret.pb(mp(x,b)); //fill second
	if(x != a) ret.pb(mp(a,y)); //fill first
	if(y != b){
		if(x >= (b-y))
			ret.pb(mp(x - (b-y), b));
		else
			ret.pb(mp(0, y+x));
	}
	if(x != a){
		if(y >= (a-x))
			ret.pb(mp(a, y-(a-x)));
		else
			ret.pb(mp(x+y,0));
	}
	vector<pii> v;
	for(int i=0; i<ret.size(); i++){
		if(!visited[ret[i].first][ret[i].second]){
			visited[ret[i].first][ret[i].second] = true;
			v.pb(ret[i]);
		}
	}
	return v;
}

int compute(){
	pii root = mp(0,0); 
	queue<pii> q; q.push(root);
	int level = 1;
	while(!q.empty()){
		queue<pii> nextQ;
		while(!q.empty()){
			pii curr = q.front(); q.pop();
			vector<pii> v = neighbours(curr);
			for(int i=0; i<v.size(); i++){
				nextQ.push(v[i]);
				if(v[i].first == c || v[i].second == c)
					return level;
			}
		}
		level++;
		q = nextQ;
	}
	return -1;
}

int main(){
	int n; cin >> n;
	while(n--){
		cin >> a >> b >> c;
		memset(visited, 0, sizeof visited);
		cout << compute() << endl;
	}
	return 0;
}