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

#define getcx getchar//_unlocked
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

const int inf = 1e9; const int maxn = 30010; const int maxq = 200010;
int ar[maxn]; int nextPos[maxn]; vpii m[maxn]; int answers[maxq];
int main(){
	int n = inp();
	for(int i=0; i<n; i++){
		ar[i] = inp();
	}
	int d,x,y; d = inp();
	for(int t=0; t<d; t++){
		x = inp(); y = inp();
		m[x-1].pb(mp(y-1,t));
	}
	vi pos(1e6+1, inf);
	BIT *b = new BIT(n);
	for(int i=n-1; i>=0; i--){
		nextPos[i] = pos[ar[i]];
		b->update(i+1, 1); //mark i'th location
		if(nextPos[i] != inf) b->update(nextPos[i]+1, -1); //unmark its next occurance
		pos[ar[i]] = i;
		for(int j=0; j<m[i].size(); j++)
			answers[m[i][j].second] = b->query(i+1, m[i][j].first+1);
	}
	for(int i=0; i<d; i++)
		printf("%d\n", answers[i]);
	return 0;
}