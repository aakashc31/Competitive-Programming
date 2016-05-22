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

ll getMaxAreaRectangle(ll* ar, int low, int high){
	if(high < low)
		return 0;
	if(low == high){
		return ar[low];
	}
	int mid = (low+high)/2;
	ll left = getMaxAreaRectangle(ar, low, mid);
	ll right = getMaxAreaRectangle(ar, mid+1, high);
	ll i = mid, j = mid+1, minH = min(ar[i],ar[j]);
	ll maxArea = minH*2;
	while(i>low || j<high){
		if(i==low){
			j++;
			minH = min(minH, ar[j]);
			maxArea = max(maxArea, minH*(j-i+1));
		}
		else if(j==high){
			i--;
			minH = min(minH, ar[i]);
			maxArea = max(maxArea, minH*(j-i+1));
		}
		else{
			if(ar[i-1] > ar[j+1]){
				i--;
				minH = min(minH,ar[i]);
				maxArea = max(maxArea, minH*(j-i+1));
			}
			else if(ar[i-1] < ar[j+1]){
				j++;
				minH = min(minH, ar[j]);
				maxArea = max(maxArea, minH*(j-i+1));
			}
			else{
				i--,j++;
				minH = min(minH, ar[j]);
				maxArea = max(maxArea, minH*(j-i+1));
			}
		}
	}
	return max(maxArea, max(left, right));
}

ll ar[100000];

int main(){
	int n = inp();
	while(n!=0){
		f(i,n) ar[i] = inp();
		printf("%lld\n",getMaxAreaRectangle(ar, 0, n-1));
		n = inp();
	}
	return 0;
}