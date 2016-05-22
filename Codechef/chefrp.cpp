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
	int t,n;
	int ar[100000];
	cin >> t;
	test(t){
		cin >> n;
		ll sum = 0;
		int min_el = 10001;
		f(i,n){
			cin >> ar[i];
			sum += ar[i];
			if(ar[i]<min_el) min_el = ar[i];
		}
		if(min_el < 2) cout << "-1"<<endl;
		else cout << sum - (min_el-2) << endl;
	}
	return 0;
}