#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<long long int> v(1,0);
	v.push_back(1);
	long long int a = 0, b = 1, s = a+b, limit = 10000000000;
	while(s<limit)
	{
		v.push_back(s);
		a=b;b=s;s=a+b;
	}
	int t;
	cin >> t;
	long long int inp;
	while(t>0)
	{
		t--;
		cin >> inp;
		if(find(v.begin(), v.end(),inp) != v.end())
		{
			cout << "IsFibo\n";
		}
		else
		{
			cout << "IsNotFibo\n";
		}
	}

}
