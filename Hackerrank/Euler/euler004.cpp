#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
typedef long long int lli;

vector<int> palins(0);


int rev(int n)
{
	int s=0;
	while(n>0)
	{
		int d = n%10;
		n/=10;
		s = s*10 + d;
	}
	return s;
}

bool isPalin(int n)
{
	return (rev(n)==n);
}

void create_palins()
{
	palins.push_back(101101);
	for(int i=100; i<=999;i++)
	{
		for(int j=100; j<=999;j++)
		{
			int pdt = i*j;
			if(isPalin(pdt) && pdt > 101101)
				palins.push_back(pdt);
		}
	}
	sort(palins.begin(),palins.end());
}

int main()
{
	create_palins();
	int t;
	getNum(t);
	while(t--)
	{
		int n;
		getNum(n);
		int i;
		for(i=0; i<palins.size(); i++)
		{
			if(palins[i] > n)
				break;
		}
		printf("%d\n",palins[i-1]);
	}
	return 0;
}