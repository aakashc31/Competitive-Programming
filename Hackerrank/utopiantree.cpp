// Hackerrank problem 1
#include <iostream>

using namespace std;

int calculate_height(int num)
{
	int i = 1;
	int h = 1;
	while(i <= num)
	{
		if(i%2!=0)
		{
			h*=2;
		}
		else
		{
			h+=1;
		}
		i++;
	}
	return h;
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
		ar[i] = calculate_height(inp);
	}

	for(int i=0; i<test_cases; i++)
		cout << ar[i] << endl;
	return 0;
}