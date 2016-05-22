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
	int t,n;
	string s,curr;
	multiset<string> M;
	cin >> t;
	string ar[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
	while(t--){
		M.clear();
		cin >> n;
		cin >> s;
		for(int i=0; i<=37; i++){
			curr = "";
			curr += s[i];
			curr += s[i+1];
			curr += s[i+2];
			M.insert(curr);
		}
		cout << n << " ";
		for(int i=0; i<8; i++){
			cout << M.count(ar[i]) << " ";
		}
		cout << endl;
	}
	return 0;
}