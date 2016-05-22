#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


void print(char ch, int c)
{
	while(c--)
		cout << ch;
}

bool isRegular(string& str)
{
	int num = 0;
	for(int i=0; i < str.length(); i++)
	{
		if(str[i] == '(')
			num++;
		else 
		{
			num--;
			if(num < 0)
				return false;
		}
	}

	return num == 0;
}

int main()
{
	string line;
	int t, k;
	cin >> t;
	while(t--)
	{
		cin >> line;
		cin >> k;
		bool isReg = isRegular(line);
		if(!isReg)
		{
			if(k > 1)
				cout << "-1" << endl;
			else
				cout << line << endl;
		}

		else
		{
			vi count(0);
			char prev = line[0];
			int cnt = 1;
			for(int i=1; i<line.length();i++)
			{
				if(line[i] == prev)
					cnt++;
				else
				{
					count.pb(cnt);
					prev = line[i];
					cnt = 1;
				}
			}
			count.pb(cnt);
			
			// for(int i=0; i<count.size(); i++)
			// 	cout << count[i] << " ";
			// cout << endl;
			if(k > count.size())
			{
				cout << "-1" << endl;
			}
			else
			{
				int cz = count.size();
				if(k<=cz/2)
					count[2*k - 1]--;
				else{
					k -= (cz/2);
					count[cz - (2*k - 1) - 1]--;
				}
				for(int i=0; i<cz; i++)
				{
					if(i&1)
						print(')', count[i]);
					else
						print('(', count[i]);
				}
				cout << endl;
			}
		}

	}
	return 0;
}