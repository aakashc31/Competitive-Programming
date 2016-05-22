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

ll getDig(string& st){
	size_t found = st.find("S");
	if(found != string::npos)
		return 0;
	int dots = 0, dashes = 0;
	f(i,st.size()){
		if(st[i] == '.')
			dots++;
		else if(st[i] == '-')
			dashes++;
	}
	return (dashes*5 + dots);
}

ll computeNum(const vector<ll>& v){
	int l = v.size();
	ll ret = v[l-1];
	ll curr = 20;
	for(int i=l-2; i>=0; i--){
		ret = ret + v[i]*curr;
		curr *= 20;
		if(curr == 400)
			curr = 360;
	}
	return ret;
}

int main(){
	int n;
	string st;
	cin >> n;
	vector<ll> v;
	while(n){
		getchar();
		v.clear();
		f(i,n){
			getline(cin, st);
			v.pb(getDig(st));
		}
		cout << computeNum(v) << endl;
		cin >> n;
	}
	return 0;
}