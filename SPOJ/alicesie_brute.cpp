#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;

int compute(int n){
	bool* flags = new bool[n+1];
	memset(flags, 1, n+1);
	int ret = 0;
	for(int i=n; i>=2; i--){
		if(!flags[i])
			continue;
		ret++;
		for(int j=2; j<i; j++){
			if(i%j == 0){
				flags[j] = false;
			}
		}
	}
	return ret;
}

int main(){
	int t,n;
	get(t);
	while(t--){
		get(n);
		printf("%d\n", compute(n));
	}
	return 0;
}