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
	int n,k;
	cin >> n;
	int *ar = new int[n];
	cin >> k;
	f(i,n)
		cin>>ar[i];
	sort(ar,ar+n);
	int i=0;
	int sum = 0;
	while(sum<=k)
		sum+=ar[i++];
	cout << (i-1)<<endl;
	return 0;
}