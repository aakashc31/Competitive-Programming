#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

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

const int inf = 1e9;
const int maxn = 1e5 + 10;

#define LSOne(i) (i & (-i))

int ft[maxn+1]; int n;
int m[maxn]; int rank[maxn][2];

int query(int k){
	int ret = inf;
	for(; k>0; k-=LSOne(k))
		ret = min(ret,ft[k]);
	return ret;
}

void update(int k, int x){
	for(; k <= n; k += LSOne(k))
		ft[k] = min(x,ft[k]);
}

int main(){
	int t = inp(),x,answer;
	while(t--){
		n = inp();
		for(int i=1; i<=n; i++){
			x = inp(); m[x] = i;
			rank[x][0] = inp(); rank[x][1] = inp();
		}
		fill(ft, ft+n+2, inf);
		answer = 1;
		update(rank[1][0], rank[1][1]);
		for(int i=2; i<=n; i++){
			if(query(rank[i][0]) > rank[i][1])
				answer++;
			update(rank[i][0], rank[i][1]);
		}
		printf("%d\n", answer);
	}
	return 0;
}