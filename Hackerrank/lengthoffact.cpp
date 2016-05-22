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


int lengthOfFactorial(int n)
{
	if(n==0)
		return 1;
	else if(n<0)
		return 0;
	double s=0;
	f(i,n)
		s+=log10(i+1);
	return ((int)(s)+1);
}

int main()
{
	cout <<"This code computes the length of factorial of the number supplied in test cases.\n";
	cout << "Enter number of test cases: ";
	int T;
	cin>>T;
	while(T-- > 0)
	{
		cout <<"Enter number: ";
		int n;
		cin >> n;
		cout << "Length of fact = "<<lengthOfFactorial(n)<<endl;
	}
	return 0;
}