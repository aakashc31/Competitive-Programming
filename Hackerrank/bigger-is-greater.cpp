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
	char str[101];
	while(t--)
	{
		cin >> str;
		int len = strlen(str);
		bool ret = next_permutation(str, str+len);
		if(ret)
			cout << str << endl;
		else
			cout << "no answer" << endl;
	}
	return 0;
}