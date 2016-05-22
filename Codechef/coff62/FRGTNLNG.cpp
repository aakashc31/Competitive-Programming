#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;

int main(){
	int t;
	string temp,x;
	cin >> t;
	while(t--){
		int n,k,l;
		cin >> n >> k;
		map<string,int> m;
		bool *ans = new bool[n];
		memset(ans, 0, n);
		for(int i=0; i<n; i++){
			cin >> x;
			m[x] = i;
		}
		for(int i=0; i<k; i++){
			cin >> l;
			for(int j=0; j<l; j++){
				cin >> temp;
				map<string,int>::iterator it = m.find(temp);
				if(it != m.end())
					ans[it->second] = true;
			}
		}
		for(int i=0;i<n;i++){
			if(ans[i])
				cout << "YES ";
			else
				cout << "NO ";
		}
		cout << endl;
	}
	return 0;
}