#include <bits/stdc++.h>
using namespace std;


#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;

// returns the number of non empty subsets of array ar, whose sum is between a and b
// also stores all the subset's sum in set1
int computeSumOfAllSubsets(int* ar, int size, int* set1, int a, int b){
	set1[0] = 0;
	int ans = 0, front = 0, newMask;
	for(int mask = 1; mask < (1<<size); mask++){
		front = 31 - __builtin_clz(mask);
		newMask = mask & (~(1<<front));
		set1[mask] = set1[newMask] + ar[front];
		if(set1[mask] >= a && set1[mask] <= b)
			ans++;
	}

	return ans;
}

int ar[34];
int set1[1048576];
int set2[1048576];

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	for(int i=0; i < n; i++) cin >> ar[i];
	if(n<21){
		int ans = computeSumOfAllSubsets(ar, n, set1, a, b);
		if(0 >= a && 0 <= b)
			ans++;
		printf("%d\n", ans);
		return 0;
	}

	//O.W. use meet in the middle.
	ll ans = 0;
	int leftHalf = (n>>1), righHalf = n-leftHalf;

	computeSumOfAllSubsets(ar, leftHalf, set1, a, b);
	computeSumOfAllSubsets(ar+leftHalf, righHalf, set2, a, b);

	sort(set2, set2+(1<<righHalf));
	for(int i=0; i<(1<<leftHalf); i++){
		int currSum = set1[i];
		ll lessThanA = lower_bound(set2, set2+(1<<righHalf), a-currSum)-set2;
		ll lessThanBPlusOne = lower_bound(set2, set2+(1<<righHalf), b+1-currSum)-set2;
		ans += (lessThanBPlusOne - lessThanA);
	}

	cout << ans << endl;
	return 0;
}