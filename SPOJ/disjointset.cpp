#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx 			getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define parent 	first
#define rank	second

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

int testDisjointSet(){
	int t,n,x,y;
	char ch;
	cin >> n;
	DisjointSet *ds = new DisjointSet(n);
	cin >> t;
	while(t--){
		cin >> ch;
		if(ch == 'f' || ch == 'F'){
			cin >> x;
			cout << ds->Find(x) << endl;
		}
		else if(ch == 'u' || ch == 'U'){
			cin >> x >> y;
			ds->Union(x,y);
		}
	}
	return 0;
}


int main(){
	return testDisjointSet();
}