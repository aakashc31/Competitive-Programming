#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)

typedef long long int ll;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int main()
{
	string a,b;
	cin >> a >> b;
	int f1[26], f2[26];
	memset(f1, 0, sizeof f1);
	memset(f2, 0, sizeof f2);
	for(int i=0; i<a.length(); i++)
		f1[a[i]-'a']++;
	for(int i=0; i<b.length(); i++)
		f2[b[i]-'a']++;
	int ans = 0;
	for(int i=0;i<26;i++)
		ans += (max(f1[i],f2[i]) - min(f1[i],f2[i]));
	cout << ans << endl;
}