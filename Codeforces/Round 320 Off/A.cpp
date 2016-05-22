#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	int x;
	cin >> x;
	int l = __builtin_clz(x);
	int max2 = 31-l;
	cout << __builtin_popcount(x) << endl;
	return 0;
}