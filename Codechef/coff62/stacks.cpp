#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;


int main(){
	int t,n,a;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> ans;
		for(int i=0; i<n; i++){
			cin >> a;
			if(ans.empty())
				ans.push_back(a);
			else{
				int l = upper_bound(ans.begin(), ans.end(), a) - ans.begin();
				if(l == ans.size())
					ans.push_back(a);
				else{
					ans[l] = a;
				}
			}
		}
		cout << ans.size() << " ";
		for(int i=0; i<ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;

	}
	return 0;
}