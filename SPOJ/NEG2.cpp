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

string convertToBaseNeg2(int num){
	string ans = "";
	while(num != 0){
		if(num > 0){
			if(num&1) ans = "1" + ans;
			else ans = "0" + ans;
			num = -1*(num/2);
		}
		else{
			int pos = -1*num;
			if(pos&1) ans = "1" + ans;
			else ans = "0" + ans;
			num = (pos+1)/2;
		}
	}
	return ans;
}

int convertFromBaseNeg2(string s){
	string st = "";
	f(i,s.size()) st += s[s.size()-1-i];
	int ans = 0, curr = 1;
	f(i,st.size()){
		ans += (st[i]-'0')*curr;
		curr *= (-2);
	}
	return ans;
}


int main(){
	int n;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	string ans = convertToBaseNeg2(n);
	cout << ans << endl;
	return 0;
}