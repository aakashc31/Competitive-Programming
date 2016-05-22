#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
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

map<pair<int,int>,int> M;
int mod = 1000000007;

int solve(int n, int p)
{
	if(n<=1)
		return 0;
	if(n==2 && p==2)
		return 3;
	if(n==2 && p==1)
		return 1;
	else
	{
		pair<int,int> pr(n,p);
		if(M.find(pr)==M.end())
		{
			int a = solve(p-1,n);
			// int b = solve(p,n-2); kuch studapa... 
			long long int c = (a+b)%mod;
			M[pr] = c;
			return c;
		}
		else
		{
			return M.find(pr)->second;
		}
	}

}

int main()
{
	int N,P;
	cin >> N >> P;
	cout << solve(N,P) << endl;
	return 0;
}