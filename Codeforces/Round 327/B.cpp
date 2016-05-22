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

int main(){
	int n,m;
	string st;
	cin >> n >> m;
	cin >> st;
	char ch[26];
	f(i,26){
		ch[i] = 'a'+i;
	}
	char c1, c2;
	f(i,m){
		cin >> c1 >> c2;
		if(c1 != c2){
			f(i,26){
				if(ch[i] == c1)
					ch[i] = c2;
				else if(ch[i] == c2)
					ch[i] = c1;
			}
		}
	}
	f(i,n){
		st[i] = ch[st[i]-'a'];
	}
	cout << st << endl;
	return 0;
}