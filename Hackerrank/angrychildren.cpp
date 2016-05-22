#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

int main()
{
	int n, k;
	cin >> n;
	long *ar = new long[n];
	long l = 0;
	cin >> k;
	while(n>0)
	{
		n--;
		long temp;
		cin >> temp;
		ar[l] = temp;
		l++;
	}
	
	sort(ar, ar+l);
	
	//slide the k length window and check which has the least difference.
	long min = ar[k-1] - ar[0];
	for(int i = 1; ;i++)
	{
		if(i+k-1 >= l)
			break;
		long newval = ar[i+k-1] - ar[i];
		if(newval < min)
			min = newval;
	}
	cout << min;
}