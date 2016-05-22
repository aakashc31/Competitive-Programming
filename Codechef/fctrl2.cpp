#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
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

int main()
{
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int n;
		cin >> n;
		int ar[50];
		int m = 1; //length
		f(i,50)
			ar[i] = 0;
		ar[0] = 1;

		for(int i=2; i<=n; i++)
		{
			//multiply i to the number represented by ar
			int carry = 0;
			f(j,m)
			{
				int x = ar[j]*i + carry;
				carry = x/10000;
				ar[j] = x%10000;
			}
			while(carry!=0)
			{
				ar[m] = carry%10000;
				carry /= 10000;
				m++;
			}
		}
		cout << ar[m-1];
		for(int i=m-2; i>=0; i--)
		{
			int t = ar[i];
			if(t==0)
				cout << "0000";
			else if(t<10)
				cout << "000" << t;
			else if(t<100)
				cout << "00" << t;
			else if(t<1000)
				cout << "0" << t;
			else
				cout << t;
		}
		cout << endl;
	}
	return 0;
}
