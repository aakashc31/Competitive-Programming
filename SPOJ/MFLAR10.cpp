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

bool isTautogram(string& s){
	int start = 0, end = s.length()-1;
	while(s[start] == ' ')
		start++;
	while(s[end] == ' ')
		end--;
	char ch = s[start];
	char other = ch+32;
	if(ch >= 'a')
		other = ch-32;
	for(int i = start; i<=end; i++){
		if(s[i] == ' '){
			if(s[i+1] != ch && s[i+1]!=other)
				return false;
		}
	}
	return true;
}

int main(){
	string st;
	getline(cin, st);
	while(st.compare("*") != 0){
		if(isTautogram(st))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		getline(cin, st);
	}
	return 0;
}