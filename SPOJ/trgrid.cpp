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

int main(){
	int t,n,m;
	get(t);
	while(t--){
		get(n); get(m);
		if(n<=m){
			if(n&1)
				cout << "R" << endl;
			else
				cout << "L" << endl;
		}
		else{
			if(m&1)
				cout << "D" << endl;
			else
				cout << "U" << endl;
		}
	}
	return 0;
}