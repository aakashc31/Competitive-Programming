//This is one of the stupidest solution I have written, ever.

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

#define f(i,n) for(int i=0; i<n; i++)
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define mp make_pair
#define pb push_back

const int modulo = 	1000000007;

bool isInside(const vi& point, const vi& dimensions)
{
	assert(point.size() == dimensions.size());
	f(i,point.size())
	{
		if(point[i]<=0 || point[i]>dimensions[i])
			return false;
	}
	return true;
}

map<pair<vi,int>,ll> dp;

ll compute(vi& point, vi& dimensions, int m)
{
	bool inside = isInside(point,dimensions);
	if(m == 0)
	{
		if(inside)
			return 1;
		else
			return 0;
	}

	if(!inside) return 0;
	
	pair<vi,int> curr = mp(point,m);
	map<pair<vi,int>,ll>::iterator it = dp.find(curr);
	if(it != dp.end())
	{
		return it->second;
	}

	ll ret = 0;
	for(int i=0; i<point.size(); i++)
	{
		//move forward in i'th dimension
		point[i]++;
		ret += compute(point, dimensions, m-1);
		ret %= modulo;
		
		//move backward
		point[i]-=2;
		ret += compute(point, dimensions, m-1);
		ret %= modulo;

		//
		point[i]++;
	}
	dp[curr] = ret;
	return ret;
}

int main()
{
	int t,n,m;
	cin >> t;
	while(t--)
	{
		dp.clear();
		cin >> n >> m;
		vi point(n,0);
		vi dimensions(n,0);
		f(i,n) cin >> point[i];
		f(i,n) cin >> dimensions[i];
		cout << compute(point,dimensions,m) << endl;
	}
	return 0;
}