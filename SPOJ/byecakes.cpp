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

int ceil_div(int a, int b){
	int ret = a/b;
	if(ret*b == a)
		return ret;
	return ret+1;
}

int main(){
	int ar[8];
	int numCakes[4];
	int ans;
	int cakes = -1;
	while(1){
		bool isLastCase = true;
		for(int i=0; i < 8; i++){
			cin >> ar[i];
			if(ar[i] != -1)
				isLastCase = false;
		}

		if(isLastCase)
			return 0;
		for(int i=0; i<4; i++)
			numCakes[i] = ceil_div(ar[i], ar[i+4]);
		cakes = *max_element(numCakes, numCakes+4);
		for(int i=0; i<4; i++){
			ans = (cakes * ar[i+4]) - ar[i];
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}