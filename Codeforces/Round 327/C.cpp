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

int n;
int ar[500050];
int newar[500050];

int mapping[] = {0,0,0,1,0,1,1,1};

bool isStable(){
	int curr;
	for(int i=0; i+2<n; i++){
		curr = ((ar[i]<<2) | (ar[i+1]<<1) | ar[i+2]);
		if(curr == 2 || curr == 5)
			return false;
	}
	return true;
}

int main(){
	n = inp();
	f(i,n) ar[i] = inp();
	int ans = 0, curr;
	bool flag;
	while(1){
		flag = true;
		for(int i=0; i+2<n; i++){
			curr = ((ar[i]<<2) | (ar[i+1]<<1) | ar[i+2]);
			if(curr == 2 || curr == 5){
				flag = false;
				newar[i+1] = 1 - ar[i+1];
			}
			else
				newar[i+1] = ar[i+1];
		}
		newar[0] = ar[0]; newar[n-1] = ar[n-1];
		if(flag)
			break;
		else
			ans++;
		swap(newar, ar);
	}
	cout << ans << endl;
	f(i,n) cout << ar[i] << " ";
	cout << endl;
	return 0;
}