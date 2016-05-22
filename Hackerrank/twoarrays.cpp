#include <iostream>
#include <vector>
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

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		int n,k;
		cin >> n >> k;
		int* ar1 = new int[n];
		int* ar2 = new int[n];
		f(i,n)
			cin>>ar1[i];
		f(i,n)
			cin >> ar2[i];
		sort(ar1,ar1+n);
		sort(ar2,ar2+n);
		int flag = 0;
		f(i,n)
		{
			if(ar1[i]+ar2[n-1-i]<k)
				flag = 1;
		}
		if(flag==1)
			cout <<"NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}