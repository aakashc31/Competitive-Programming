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
	int t;
	cin >> t;
	while(t--)
	{
		string a;
		cin >> a;
		int l = a.length();
		if(l&1)
		{
			cout << "-1" << endl;
			continue;
		}
		int f1[26], f2[26];
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		for(int i=0; i<l/2; i++)
			f1[a[i]-'a']++;
		for(int i=l/2; i<l; i++)
			f2[a[i]-'a']++;
		int ans = 0;
		for(int i=0; i<26; i++)
		{
			if(f1[i] > f2[i])
				ans += (f1[i] - f2[i]);
		}
		cout << ans << endl;
	}
	return 0;
}