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
typedef vector<vi>		vvi;

const int maxn = 200050;
const ll modulo = 1e9 + 7;
char st[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin >> st;
	int n = strlen(st);
	ll prev = st[0]-'0', curr, ans = prev;
	for(int i=1; i<n; i++){
		curr = (prev*10 + (i+1ll)*(st[i]-'0'))%modulo;
		ans = (ans + curr) % modulo;
		prev = curr;
	}
	cout << ans << endl;
	return 0;
}
