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
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

int main()
{
	int N;
	cin>>N;
	vector<int> v(101,0);
	while(N>0)
	{
		N--;
		int i;
		cin>>i;
		v[i]++;
	}
	int c = 0;
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)
	{
		if(*it == 1)
		{
			break;
		}
		c++;
	}
	cout << c << endl;
}