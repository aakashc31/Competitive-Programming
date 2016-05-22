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

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

// a != b
inline char addThird(char a, char b){
	for(char ch = 'a'; ch <= 'z'; ch++){
		if(ch!=a && ch!=b)
			return ch;
	}
	return '\0';
}

int main(){
	int n,t;
	cin >> n >> t;
	string a,b,ans;
	cin >> a >> b;
	int y = 0;
	f(i,n){
		if(a[i] == b[i])
			y++;
	}
	int x = n-t; //we need exactly x same chars
	if(x <= y){
		int similar = 0;
		ans = "";
		f(i,n){
			if(similar < x){
				if(a[i] == b[i]){
					ans += a[i];
					similar += 1;
				}
				else{
					ans += addThird(a[i], b[i]);
				}
			}
			else ans+= addThird(a[i], b[i]);
		}
		cout << ans << endl;
		return 0;
	}

	//x > y
	int disjLen = n - y;
	int interNeeded = x-y;
	if(2*interNeeded <= disjLen){
		ans = "";
		int inter1 = 0, inter2 = 0;
		f(i,n){
			if(a[i] == b[i])
				ans += a[i];
			else{
				if(inter1 < interNeeded){
					ans += a[i];
					inter1++;
				}
				else if(inter2 < interNeeded){
					ans += b[i];
					inter2++;
				}
				else{
					ans += addThird(a[i], b[i]);
				}
			}
		}
		cout << ans << endl;
	}
	else
		cout << "-1" << endl;
	return 0;
}