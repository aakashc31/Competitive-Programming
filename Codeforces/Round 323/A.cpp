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

bool V[51], H[51];

int main(){
	int n,x,y;
	cin >> n;
	for(int i=0; i<n*n;i++){
		cin >> x >> y;
		if((!H[x]) && (!V[y])){
			cout << i+1 << " ";
			H[x] = true;
			V[y] = true;
		}
	}
	cout << endl;
	return 0;
}