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

#define maxn 100050

char st[maxn];
int Z[maxn];
int n; //

// Z[i] denotes the longest substring starting at index i, which is also a prefix of st
// L,R is such that L<=i<=R and L,R is a proper prefix of the string with maximum R
// http://codeforces.com/blog/entry/3107
void createZArray(){
	int L = 0, R = 0, k;
	for(int i=1; i<n; i++){
		if(i > R){
			L = R = i;
			while(R < n && st[R-L] == st[R]) R++;
			Z[i] = R-L; R--;
		}
		else{
			k = i - L;
			if(Z[k] < (R-i+1)) Z[i] = Z[k];
			else{
				L = i;
				while(R < n && st[R-L] == st[R]) R++;
				Z[i] = R-L; R++;
			}
		}
	}
}