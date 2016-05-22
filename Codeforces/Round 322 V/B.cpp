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

int ar[100000], br[100000];

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	br[n-1] = ar[n-1];
	for(int i=n-2; i>=0; i--)
		br[i] = max(ar[i], br[i+1]);
	for(int i=0; i<n-1; i++){
		if(ar[i] > br[i+1])
			cout << "0 ";
		else
			cout << br[i+1] - ar[i] + 1 << " ";
	}
	cout << 0 << endl;
	return 0;
}