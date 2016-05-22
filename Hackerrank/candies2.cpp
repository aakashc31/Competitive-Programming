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

int ar[100010];


int main(){
	int n = inp();
	for(int i=0; i<n; i++)
		ar[i] = inp();
	int left = 0, right = 0, curr = 1, ans = 0,c;
	while(1){
		if(right == n-1){
			ans += curr;
			if(left == right)
				break;
			c = right-left+1;
			if(c < curr)
				c--;
			else
				ans -= curr;
			ans += (c*(c+1))/2;
			break;
		}
		else{
			if(ar[right+1] < ar[right])
				right++;
			else{
				ans += curr;
				c = right-left+1;
				if(c < curr)
					c--;
				else
					ans -= curr;
				ans += (c*(c+1))/2;
				if(left==right && ar[right+1] > ar[right]) 
					curr++;
				else
					curr = (ar[right+1] == ar[right]) ? 1 : 2;
				right++;
				left = right;
			}
		}
	}
	cout << ans << endl;
	return 0;
}