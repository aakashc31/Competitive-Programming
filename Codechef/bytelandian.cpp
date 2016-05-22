#include <iostream>
#include <vector>
#include <map>
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
#define f(i,n) for(int i=0;i<n;i++)

map<long long int,long long int> table;
long long int bytecoins(long long int n)
{
	if(n==1 || n==0)
		return n;
	else
	{
		if(table.find(n)!=table.end())
		{
			return table.find(n)->second;
		}
		long long int a = n/2;
		long long int b = n/3;
		long long int c = n/4;
		long long int s = bytecoins(a)+bytecoins(b)+bytecoins(c);
		if(s>n)
		{
			table[n] = s;
			return s;
		}
		else
		{
			table[n] = n;
			return n;
		}
	}
}
int main()
{
	long long int c;
	int case_ = 0;
	while((cin>>c) && case_<=10)
	{	
		case_++;
		cout << bytecoins(c) << endl;
	}
	return 0;
}

