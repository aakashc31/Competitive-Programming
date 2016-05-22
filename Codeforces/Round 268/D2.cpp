#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

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

class DisjointSet{
private:
	pii* ar;
	int size;
public:
	DisjointSet(int n){
		size = n;
		ar = new pii[n];
		for(int i=0; i<n; i++) ar[i] = mp(i,0);	
	}
	// uses path compression
	int Find(int n){
		assert((n < size) && (n>=0));
		if(ar[n].parent != n)
			ar[n].parent = Find(ar[n].parent);
		return ar[n].parent;
	}
	// uses Union by rank
	void Union(int x, int y){
		assert((x < size) && (x>=0));
		assert((y < size) && (y>=0));
		int xRoot = Find(x);
		int yRoot = Find(y);
		if(xRoot == yRoot)
			return;
		if(ar[xRoot].rank < ar[yRoot].rank)
			ar[xRoot].parent = yRoot;
		else if(ar[xRoot].rank > ar[yRoot].rank)
			ar[yRoot].parent = xRoot;
		else{
			ar[yRoot].parent = xRoot;
			ar[xRoot].rank += 1;
		}
	}
};


ll n,a,b;
map<int,int> M;
ll ar[100010];
int ans[100010];
set<int> S1, S2;

int main(){
	int x;
	n = inp(); a= inp(); b = inp();
	f(i,n){
		x = inp();
		M[x] = i;
		ar[i] = x;
	}
	map<int,int>::iterator it1,it2;

	DisjointSet* ds = new DisjointSet(n);
	bool flag = true;
	for(int i=0; i<n; i++){
		it1 = M.find(a - ar[i]);
		it2 = M.find(b - ar[i]);
		if(it1 != M.end()){
			ds->Union(i, it1->second);
			if(it2 != M.end())
				ds->Union(i, it2->second);
		}
		else if(it2 != M.end()){
			ds->Union(i, it2->second);
		}
		else{
			flag = false;
			break;
		}
	}
	if(flag){
		int par1 = -1, par2 = -1;
		for(int i=0; i<n; i++){
			par = ds->Find(i);
			if(par1==-1 && par2==-1){
				par1 = par;
				S1.insert(ar[i]);
			}
			else if(par == par1){
				S1.insert(ar[i]);
			}
			else if(par2 == -1){
				par2 = par;
				S2.insert(ar[i]);
			}
			else if(par == par2){
				S2.insert(ar[i]);
			}
			else{
				flag = false;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
			return 0;
		}
		for(set<int>::iterator it = S1.begin(); it!=S1.end(); it++){
			if(count(a -))
		}
	}
	else{
		printf("NO\n");
	}

}