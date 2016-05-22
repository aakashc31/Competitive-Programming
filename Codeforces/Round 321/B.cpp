#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

pii ar[100005];

int main(){
	int n,d,m,s;
	cin >> n >> d;
	for(int i=0; i<n; i++){
		cin >> m >> s;
		ar[i] = make_pair(m,s);
	}
	sort(ar, ar+n);
	int l = 0, r = 0;
	ll totFriend = ar[0].second;
	ll ans = ar[0].second;
	while(r < n-1){
		//curr window is of ar[l..r]
		if(ar[r+1].first - ar[l].first < d){
			totFriend += ar[r+1].second;
			r++;
		}
		else{
			totFriend += ar[r+1].second;
			r++;
			while(l<r){
				if(ar[r].first - ar[l].first >= d){
					totFriend -= ar[l].second;
					l++;
				}
				else
					break;
			}
		}
		ans = max(totFriend, ans);
	}
	cout << ans << endl;
	
	return 0;
}