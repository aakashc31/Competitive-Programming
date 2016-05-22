#include <bits/stdc++.h>
 
using namespace std;
 
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second
 
typedef long long LL;
LL MOD = 1000000007;
multiset<int> s1, s2;
 
void solve()
{
	int N;
	vector<int> ans;
	cin >> N;
	for(int i=0;i<(1<<N);++i){
		int x; cin >> x;
		s1.insert(x);
	}
	multiset<int> :: iterator it1, it2;
	while(s1.size() > 1){
		it1 = ++s1.begin();
		int v = *it1 - *s1.begin();
		s2.clear();
		ans.push_back(v);
		
		while(s1.size() > 0){
			int xx = *s1.begin();
			s2.insert(xx);
			it2 = s1.find(xx+v);
			s1.erase(it2);
			it2 = s1.find(xx);
			s1.erase(it2);
		}
		s1 = s2;
	}
	assert(ans.size() == N);
	for(int i=0;i<N;++i){
		cout << ans[i] << " ";
	}
	cout << endl;
	ans.clear();
	return ;
}
 
int main()
{
	int T;
	cin >> T;
	while(T--){
		s1.clear();
		s2.clear();
		solve();
	}
	return 0;
}