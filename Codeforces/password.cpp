// http://codeforces.com/contest/126/problem/B
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

#define maxn 1000050

char st[maxn];
int Z[maxn];
int n; 

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
				Z[i] = R-L; R--;
			}
		}
	}
}

int main(){
	cin >> st;
	n = strlen(st);
	createZArray();
	int maxlen = -1, res = -1;
	for(int i=1; i<n; i++){
		if(Z[i] == n-i && n-i <= maxlen){
			res = n-i;
			break;
		}
		maxlen = max(maxlen, Z[i]);
	}
	if(res == -1)
		cout << "Just a legend" << endl;
	else{
		st[res] = '\0';
		cout << st << endl;
	}
	return 0;
}