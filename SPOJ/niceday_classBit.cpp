#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define getcx getchar_unlocked
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
#define LSOne(i) (i & (-i))
class BIT{
private:
	vi ft;
public:
	BIT(int n){
		ft.resize(n+1,inf);
	}
	int query(int k){
		int ret = inf;
		for(; k>0; k-=LSOne(k))
			ret = min(ret,ft[k]);
		return ret;
	}
	void update(int k, int x){
		for(; k < ft.size(); k += LSOne(k))
			ft[k] = min(x,ft[k]);
	}
};


const int maxn = 1e5 + 10;
int m[maxn]; int rank[maxn][2];

int main(){
	int t = inp(),n,x;
	while(t--){
		n = inp();
		for(int i=1; i<=n; i++){
			x = inp(); m[x] = i;
			rank[x][0] = inp(); rank[x][1] = inp();
		}
		BIT* b = new BIT(n);
		int answer = 1;
		b->update(rank[1][0], rank[1][1]);
		for(int i=2; i<=n; i++){
			if(b->query(rank[i][0]) > rank[i][1])
				answer++;
			b->update(rank[i][0], rank[i][1]);
		}
		printf("%d\n", answer);
	}
	return 0;
}