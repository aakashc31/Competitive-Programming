#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int,char*> pistr;
vvi table(100,vi(0));
pistr ar[1000000];

int main()
{
	int n,x;
	g(n);
	f(i,n)
	{
		g(x);
		char* ch = new char[11];
		scanf("%s",ch);
		ar[i] = make_pair(x,ch);
		table[x].push_back(i);
	}
	f(i,table.size())
	{
		f(j,table[i].size())
		{
			int index = table[i][j];
			if(index < n/2)
				printf("- ");
			else
				printf("%s ",ar[index].second);
		}
	}
	return 0;
}
