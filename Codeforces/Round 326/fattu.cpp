#include <bits/stdc++.h>
using namespace std;
int freq[26];
int main(){
	string s; cin >> s;
	int n = s.length();
	for(int i=0;i<n;i++) freq[s[i]-'a']++;
	sort(freq,freq+26); int ans = n;
	for(int l=1;l<=26;l++){
		if(n%l) continue; int cur = 0;
		for(int i=0;i<26;i++){
			if(i<l) cur += abs(n/l - freq[25-i]);
			else cur += freq[25-i];
		}
		ans = min(ans,cur/2);
	}
	cout << ans;
}