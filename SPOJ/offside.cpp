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
	int A,D;
	int *B = new int[11];
	int *C = new int[11];
	cin >> A >> D;
	while(1){
		if(A==0 && D==0)
			break;
		for(int i=0; i<A; i++)
			cin >> B[i];
		for(int i=0; i<D; i++)
			cin >> C[i];
		sort(C,C+D);
		int closestAttacker = *min_element(B, B+A);
		int def1 = C[0], def2 = C[1];
		if(closestAttacker < def2)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		cin >> A >> D;
	}
	return 0;
}