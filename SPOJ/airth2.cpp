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

#define PLUS 	1
#define MINUS	2
#define MULT	3
#define DIV		4
#define NOP		0

ll stringToLL(string st){
	if(st.size() == 0)
		return 0;
	ll ret = 0;
	for(int i=0; i<st.length(); i++)
		ret = ret*10 + (st[i] - '0');
	return ret;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string st;
		int op = NOP; string ch;
		cin >> st;
		ll ans = stringToLL(st), curr;
		cin >> st;
		while(!st.compare("=") == 0){
			ch = st;
			cin >> st;
			curr = stringToLL(st);
			if(ch.compare("+") == 0)
				ans += curr;
			else if(ch.compare("-") == 0)
				ans -= curr;
			else if(ch.compare("*") == 0)
				ans *= curr;
			else if(ch.compare("/") == 0)
				ans /= curr;

			cin >> st;
		}
		cout << ans << endl;	
	}
	return 0;
}
