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


int main(){
	n = inp();
	f(i,n) ar[i] = inp();

	int ans = 0;
	int start = 0, end, curr,len;
	while(start < n-1){
		if(ar[start] == ar[start+1]){
			start++;
		}
		else{
			end = start+1;
			len = 2;
			while(end < n-1 && ar[end] != ar[end+1]){
				end++;
				len++;
			}
			if(ar[start] == ar[end]){
				ans = max(ans, (end-start+1)/2);
				curr = ar[start];
				while(start<=end){
					ar[start++] = curr;
				}
			}
			else{
				ans = max(ans, ((end-start+1)/2) -1);
				len = (end-start+1)/2;
				curr = ar[start];
				for(int i=0; i<len; i++){
					ar[start+i] = curr;
				}
				for(int i=0; i<len; i++){
					ar[start+len+i] = 1-curr;
				}
				start = end+1;
			}
		}

	}
	cout << ans << endl;
	f(i,n) cout << ar[i] << " ";
	cout << endl;
}