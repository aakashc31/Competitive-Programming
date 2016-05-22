// Hackerrank problem 3
#include <iostream>

using namespace std;

//number of chocolate pieces of 1 by 1 size that can be formed.
long getans(int n)
{
	long r = n/2;
	long c = n-r;
	return r*c;
}

int main()
{
	int test_cases;
	cin >> test_cases;
	long ar[test_cases];
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