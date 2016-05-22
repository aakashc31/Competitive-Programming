#include <bits/stdc++.h>
using namespace std;

#define pb 				push_back
#define mp 				make_pair

typedef long long int 	ll;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

const int maxn = 200010;
int a[maxn];

int main(){
	int t,n,k; cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=0; i<n; i++)
			cin >> a[i];
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				if(*max_element(a+i, a+j+1) > k)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}