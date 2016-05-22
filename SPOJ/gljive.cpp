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

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int main(){
	int ar[10];
	for(int i=0; i<10; i++){
		cin >> ar[i];
	}

	// vector<int> v;
	// for(int mask = 0; mask < (1<<10); mask++){
	// 	int sum = 0;
	// 	for(int i=0; i<10; i++){
	// 		if(mask & (1<<i))
	// 			sum += ar[i];
	// 	}
	// 	v.push_back(sum);
	// }
	// sort(v.begin(), v.end());
	// if(v[v.size()-1] < 100)
	// 	cout << v[v.size()-1] << endl;
	// else
	// 	cout << *(lower_bound(v.begin(), v.end(), 100)) << endl;

	int pref[10];
	pref[0] = ar[0];
	int small = -1, great = -1;
	for(int i=1; i<=9; i++) pref[i] = pref[i-1]+ar[i];

	for(int i=0; i<10; i++){
		if(pref[i] == 100){
			cout << 100 << endl;
			return 0;
		}
		else if(pref[i] < 100)
			small = pref[i];
		else{
			great = pref[i];
			break;
		}
	}

	if(small == -1)
		cout << great;
	else if(great == -1)
		cout << small;
	else{
		int d1 = 100-small;
		int d2 = great - 100;
		if(d1 < d2)
			cout << small << endl;
		else
			cout << great << endl;
	}
	return 0;
}