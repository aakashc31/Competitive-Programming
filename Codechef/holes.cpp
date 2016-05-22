#include <iostream>
#include <stack>
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
	int ar[] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	int t;
	cin >> t;
	while(t-- > 0)
	{
		 string s;
		 cin >> s;
		 int ans = 0;
		 f(i,s.length())
		 {
		 	char ch = s[i];
		 	int a = ch - 65;
		 	ans += ar[a];
		 }
		 cout << ans << endl;
	}
	return 0;
}