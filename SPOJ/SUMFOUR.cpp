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


inline int binary_search(int *ar, int len, int x){
	int low = 0, high = len-1, mid = 0;
	while(low <= high){
		if(low == high){
			if(ar[low] == x) return 1;
			else return 0;
		}
		mid = (low+high)/2;
		if(ar[mid] == x)
			break;
		else if(x < ar[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	int ret = 0;
	int j = mid;
	while(j >= 0 && ar[j] == x)
		j--,ret++;
	j = mid+1;
	while(j<len && ar[j]==x)
		j++,ret++;
	return ret;
}

// void testBinarySearch(){
// 	int n;
// 	cin >> n;
// 	int *ar = new int[n];
// 	f(i,n) cin >> ar[i];
// 	int x;
// 	cin >> x;
// 	cout << binary_search(ar, n, x) << endl;
// }

int A[4000], B[4000], C[4000], D[4000];
int comb[16000000];

int main(){
	int n = inp();
	f(i,n){
		A[i] = inp();
		B[i] = inp();
		C[i] = inp();
		D[i] = inp();
	}
	f(i,n){
		f(j,n){
			comb[i*n + j] = A[i]+B[j];
		}
	}
	sort(comb, comb + n*n);
	ll ans = 0;
	int curr;
	f(i,n){
		f(j,n){
			curr = C[i] + D[j];
			ans += binary_search(comb, n*n, -1*curr);
		}
	}
	printf("%lld\n", ans);
	return 0;
}