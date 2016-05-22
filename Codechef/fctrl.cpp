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
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int n;
		scanf("%d", &n);
		int p = 5;
		int s = n/p;
		int numZ = 0;
		while(s!=0)
		{
			numZ += s;
			p = p*5;
			s = n/p;
		}
		printf("%d\n", numZ);
	}
	return 0;
}