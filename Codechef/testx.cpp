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
	int x,y;
	while(1){
		cin >> x >> y;
		if(x&y != 0)
			cout << (x&y!=0)<< "yoyo\n";
		else
			cout << (x&y!=0) << "nono\n";

		if(x&y)
			cout << "xoxox\n";
		else
			cout << "bobo\n";
	}
}