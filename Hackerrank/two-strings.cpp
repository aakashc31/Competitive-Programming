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
		string a,b;
		cin >> a >> b;
		int flags[26];
		memset(flags, 0, sizeof flags);
		for(int i=0; i<a.length();i++)
			flags[a[i]-'a'] = 1;
		bool flag = true;
		for(int j=0; j<b.length(); j++)
		{
			if(flags[b[j]-'a'] == 1)
			{
				cout << "YES" << endl;
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "NO" << endl;
	}
	return 0;
}