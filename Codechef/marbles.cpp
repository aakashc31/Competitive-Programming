#include <iostream>
#include <vector>
#include <map>
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

map<pair<int,int>, long long int> table;

long long int ncr(int n, int r)
{
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	pair<int,int> p(n,r);
	if(table.find(p) != table.end())
	{
		return table.find(p)->second;
	}
	else
	{
		long long int a = ncr(n-1,r);
		long long int b = ncr(n-1,r-1);
		table[p] = a+b;
		return a+b;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int n,k;
		cin >> n >> k;
		cout << ncr(n-1,k-1) << endl;
	}
	return 0;
}