#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define LSOne(i) (i & (-i))
class BIT{
private:
	vi ft;
public:
	BIT(int n){
		ft.resize(n+1,0);
	}
	int query(int k){
		int sum = 0;
		for(; k>0; k-=LSOne(k))
			sum += ft[k];
		return sum;
	}
	int query(int i, int j){
		if(i>j) return 0;
		return query(j) - (i == 1 ? 0 : query(i-1));
	}
	void update(int k, int x){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] += x;
	}
};

#define getcx 			getchar//_unlocked
inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

const int inf = 1e9;
const int maxn = 30010;
const int maxq = 200010;
int ar[maxn]; int nextPos[maxn];
vpii m[maxn]; int answers[maxq];
int main(){
	int n = inp();
	for(int i=0; i<n; i++){
		ar[i] = inp();
	}
	vi pos(1e6+1, inf);
	for(int i=n-1; i>=0; i--){
		nextPos[i] = pos[ar[i]];
		pos[ar[i]] = i;
	}
	//now nextPos[i] stores the index of element same as ar[i], leftmost to the right
	int d,x,y; d = inp();
	for(int t=0; t<d; t++){
		x = inp(); y = inp();
		m[x-1].pb(mp(y-1,t));
	}
	BIT *b = new BIT(n);
	for(int i=0; i<n; i++){
		if(pos[ar[i]] == i){
			// cout << "Marking .. " << i+1 << endl;
			b->update(i+1, 1);
		}
	}
	for(int k=0; k<n; k++){
		if(m[k].empty()){
			// cout << "Marking (ij).. " << nextPos[k]+1 << endl;
			if(nextPos[k]!=inf) b->update(nextPos[k]+1, 1);
			continue;
		}
		int start = k;
		vpii &v = m[k];
		for(int i=0; i<v.size(); i++){
			answers[v[i].second] = b->query(start+1, v[i].first+1);
		}
		if(nextPos[start] != inf) b->update(nextPos[start]+1, 1);
		// if(nextPos[start] != inf) cout << "Marking(in) .. " << nextPos[start]+1 << endl;
	}
	for(int i=0; i<d; i++)
		printf("%d\n", answers[i]);
	return 0;
}