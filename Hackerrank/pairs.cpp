// Given N numbers, count the total pairs of numbers that have a difference of K.
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
	int N,K;
	cin >> N >> K;
	int l = 0;
	int* ar = new int[N];
	while(l<N)
		cin >> ar[l++];
	sort(ar, ar+N);
	int s = 0;
	for(int i=0; i<l; i++)
	{
		if(binary_search(ar+i+1,ar+l,ar[i]+K))
			s++;
	}
	cout << s <<endl;
	return 0;
}