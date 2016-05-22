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

int main(){
	vector<int> v(5,0);
	vector<int> x(4,-1);

	v.insert(v.end(),x.begin(), x.end());
	f(i,v.size())
		cout << v[i] << " ";
	cout << endl;
	return 0;
}