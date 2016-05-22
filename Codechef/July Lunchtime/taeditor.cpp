#include <bits/stdc++.h>

using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;
char st[100000];
int main()
{
	string s = "b";
	int q;
	getNum(q);
	char ch;
	while(q--)
	{
		cin >> ch;
		if(ch=='+')
		{
			// cout << "yo\n";

			int i;
			
			getNum(i);
			// printf("%d\n",i );
			scanf("%s",st);
			string temp = st;
			s.insert(i,temp);
		}
		else
		{
			int i1,i2;
			getNum(i1), getNum(i2);
			cout << s.substr(i1-1,i2) << endl;
		}
	}

	return 0;
}