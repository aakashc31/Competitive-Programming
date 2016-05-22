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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


/*
 I need to have atleast n-k+1 good integers. In this way if you select any k integers, you'll have one good integer in it. 
	k = 1: make all good. if a[i]<L then L-a[i], if a[i] > R then a[i]-R, else 0
	sort them. Find L and R. Now you know how many integers are between
*/


int main(){
	int t,n,l,r;
	cin >> t;
	int ar[100000];
	test(t){
		cin >> n >> l >> r;
		f(i,n) cin >> ar[i];
		sort(ar, ar+n);
		int smaller = lower_bound(ar, ar+n, l) - ar; //number of elements smaller than l
		int larger = n - (upper_bound(ar, ar+n, r)- ar); //number of elements larger than r
		int dist[smaller+larger];
		f(i, smaller) dist[i] = l - ar[i];
		f(i, larger) dist[smaller + i] = ar[n-larger+i] - r;
		sort(dist, dist + smaller + larger);
		int notGood = smaller+larger;
		ll prefixSum[notGood];
		prefixSum[0] = dist[0];
		for(int i=1; i<notGood; i++) prefixSum[i] = prefixSum[i-1] + dist[i]; 
		int alreadyGood = n - (smaller + larger);
		for(int k=1; k<=n; k++){
			int needed = n-k+1 - alreadyGood;
			if(needed > 0)
				cout << prefixSum[needed-1] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
	return 0;
}