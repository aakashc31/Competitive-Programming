#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx 			getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

inline ll inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

int main(){
	int t;
	cin >> t;
	string st, rev;
	bool flag;
	size_t found;
	while(t--){
		rev = "";
		flag = true;
		cin >> st;
		int l = st.length();
		f(i,l) rev += st[l-1-i];
		f(i,l){
			for(int j=i+1; j<l; j++){
				found = rev.find(st.substr(i, j-i+1));
				if(found == string::npos){
					flag = false;
					goto outer;
				}
			}
		}
		outer:
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}