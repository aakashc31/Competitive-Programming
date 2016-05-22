#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;
#define getcx 			getchar//_unlocked
inline ll inp()//fast input function
{
	ll n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}

inline int fiter(int n, int d){
	if(n==1)
		return 1;
	int k = (d&1) ? 2 : 1; //for n = 2
	for(int p = 3; p <= n; p++)
		k = ((k+d-1)%p)+1;
	return k;
}

int main(){
	int n = inp(); int d = inp();
	while(n != 0 || d != 0){
		printf("%d %d %d\n",n,d,fiter(n,d));
		n = inp(); d = inp();
	}
	return 0;
}