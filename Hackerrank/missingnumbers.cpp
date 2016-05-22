#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
	int n,m;
	cin>>n;
	int* ar = new int[n];
	int minA = 10000;
	f(i,n)
	{
		cin>>ar[i];
		if(ar[i] < minA)
			minA = ar[i];
	}
	
	cin >> m;
	int *br = new int[m];
	int minB = 10000;
	f(i,m)
	{
		cin >> br[i];
		if(br[i] < minB)
			minB = br[i];
	} 

	int flagB[101];
	f(i,101) {flagB[i] = 0;}

	f(i,m)
	{
		int t = (br[i]-minB);
		if(t>=0 && t<=100)
			flagB[t] = flagB[t]+1;
	}

	f(i,n)
	{
		int ith = ar[i];
		int posinflag = ar[i]-minB;
		if(posinflag<0 || posinflag>100)
		{}
		else if(flagB[ar[i]-minB]>0)
			(flagB[posinflag])--;
	}

	vi p(0,0);
	f(i,101)
	{
		if(flagB[i]>0)
		{
	
			p.push_back(i+minB);
		}
	}

	sort(all(p));
	for(vi::iterator it = p.begin();it!=p.end();it++)
	{
		cout << *it << " ";
	}
	return 0;
}