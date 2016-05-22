// Hackerrank problem 2
#include <iostream>

using namespace std;

int getans(int n)
{
	if(n<2)
		return 0;
	else
		return (n*(n-1))/2;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	int ar[test_cases];
	for(int i=0; i<test_cases; i++)
	{
		int inp;
		cin >> inp;
		ar[i] = getans(inp);
	}

	for(int i=0; i<test_cases; i++)
		cout << ar[i] << endl;
	return 0;
}