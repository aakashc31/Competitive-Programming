#include <iostream>
using namespace std;

// This will return the number of fives, ie, it will be divisibe by three
int numfives(int k)
{
	int f = 3*(k/3);
	int t = k - f;
	int flag = 0;
	while(t % 5 != 0)
	{
		f -= 3;
		t +=3;
		if(f<0)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		return -1;
	}
	return f;
}

void print_num(int num, int k)
{
	for(int i=0; i<num; i++)
	{
		cout << "5";
	}
	for(int i=0; i < k; i++)
	{
		cout << "3";
	}		
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
	{
		int n;
		cin >> n;
		int num = numfives(n);
		if(num==-1)
			cout << "-1"<<endl;
		else
			print_num(num, n-num);
	}
}