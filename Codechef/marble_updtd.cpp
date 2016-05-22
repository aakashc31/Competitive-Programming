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


long long int ncr(long n, long r)
{
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	long long s = 1.0;
	int aa = n-r+1;
	f(i,r)
	{
		s = s*(aa+i)/(i+1);
	}
	// long long int a =s;
	return s;
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		long n,k;
		cin >> n >> k;
		cout << ncr(n-1,k-1) << endl;
	}
	return 0;
}