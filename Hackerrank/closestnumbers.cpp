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
	cin >> N;
	int* ar = new int[N];
	int l = 0;
	while(l<N)
	{
		cin >> ar[l++];
	}
	sort(ar, ar+l);
	int min = abs(ar[1] - ar[0]);
	vector< pair<int, int> > pairs;
	pairs.push_back(pair<int,int>(ar[0],ar[1]));
	for(int i=1; i<l-1;i++)
	{
		int diff = abs(ar[i] - ar[i+1]);
		if(diff < min)
		{
			min = diff;
			pairs.clear();
			pairs.push_back(pair<int,int>(ar[i],ar[i+1]));
		}
		else if(diff == min)
		{
			pairs.push_back(pair<int,int>(ar[i],ar[i+1]));
		}
		else
		{

		}
	}

	for(vector< pair<int, int> >::iterator it = pairs.begin(); it!= pairs.end(); it++)
	{
		pair<int,int> p = *it;
		cout << p.first << " "<<p.second << " ";
	}
	cout << endl;
	return 0;
}