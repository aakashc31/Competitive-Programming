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

set<pair<ll,ll> > S;

inline int getLen(ll n){
	if(n==0) return 1;
	int ret = 0;
	while(n > 0){
		ret++;
		n /= 10;
	}
	return ret;
}

inline ll getNum(string& s){
	ll ret = 0;
	f(i,s.size())
		ret = ret*10 + (s[i]-'0');
	return ret;
}

pair<ll,ll> ar[10000];

int main(){
	ll t = inp(), num, n, currLen;
	string st;
	pii curr;
	while(t--){
		S.clear();
		n = inp();
		f(i,n) {
			cin >> st;
			ar[i] = mp((ll)st.length(), getNum(st));
		}
		sort(ar, ar+n);
		bool ans = true;
		for(int i=n-1; i>=0; i--){
			currLen = ar[i].first;
			curr = ar[i];
			if(S.count(curr) != 0){
				// cout << "Found " << curr.first << " " << currLen << endl;
 				ans = false;
				break;
			}
			num = ar[i].second;
			while(currLen > 0){
				// cout << "inserting " << num << " " << currLen << endl;
				curr = mp(currLen,num);
				S.insert(curr);
				num /= 10;
				currLen -= 1;
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}