#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int s = 0; // no. of open tweets
	int n,k;
	cin >> n >> k;
	bool *isOpen = new bool[n];
	f(i,n)
		isOpen[i] = false;
	while(k-- > 0)
	{
		string inp;
		cin >> inp;
		if(inp.compare("CLOSEALL")==0)
		{
			f(i,n)
				isOpen[i] = false;
			s = 0;
		}
		else
		{
			int t;
			cin >> t;
			if(isOpen[t-1])
			{
				isOpen[t-1] = false;
				s--;
			}
			else
			{
				isOpen[t-1] = true;
				s++;
			}
		}
		cout << s <<endl;
		fflush(stdin);
	}
	return 0;
}