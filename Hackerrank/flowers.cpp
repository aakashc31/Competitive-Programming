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

long long int summate(int* first, int* last)
{
	long long int s =0;
	 if(first != last) { 
           while(true) { 
                s+= (*first); 
                first++; 
                if(first == last) { 
                     break; 
                }  
           } 
      } 
      return s;
}

int main()
{
	int N,K;
	cin >> N >> K;
	int* costs = new int[N];
	int l=0;
	while(l<N)
	{
		cin >> costs[l++];
	}
	sort(costs,costs+l);
	long long int sum = 0;
	int factor = 1;
	while(l>K)
	{
		sum += factor*summate(costs+l-K,costs+l);
		l-=K; factor++;
	}
	sum += factor*summate(costs, costs+l);
	cout << sum <<endl;
	return 0;
}