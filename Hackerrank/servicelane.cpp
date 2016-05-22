#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push	_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

int main()
{
	int N, T;
	cin >> N >> T;
	int l = 0;
	int *ar = new int[N];
	while(l < N)
	{
		cin >> ar[l];
		l++;
	}
	//Now the width array has been stored in ar

	//take the test cases one by one and solve them
	while(T > 0)
	{
		int i, j;
		cin >> i >> j;
		int k = *min_element(ar+i, ar+j+1);
		cout << k << endl;
		T--;
	}
	return 0;
}