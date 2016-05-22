#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked


typedef long long int ll;
typedef long long int lli;


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


int main(){
	std::ios::sync_with_stdio(false);
	int a,b;
	scanf("%de%d", &a, &b);
	while(a!=0 || b!=0){
		int n = a;
		while(b--)
			n*=10;
		int init = 1, cd = 2, start = (n&1) , oldStart;
		n = (n+1)/2;
		while(n>1){
			if(start == 1)
				init += cd;
			cd = (cd<<1);
			oldStart = start;
			start = (oldStart == 0) ? (n&1) : ((~n)&1);
			if(oldStart == 0)
				n = (n+1)/2;
			else 
				n /= 2;
		}
		cout << init << endl;
		scanf("%de%d", &a, &b);
	}
}