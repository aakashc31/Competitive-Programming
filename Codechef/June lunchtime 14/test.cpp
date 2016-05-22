#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define getNum(n) scanf("%d",&n)


int gcd(int a,int b)
{
	if(b==0)
		return a;
	else if(a==0)
		return b;
	else
		return gcd(b,a%b);
}
int main()
{
	int a,b;
	cin >> a >>b;
	cout << gcd(a,b) <<endl;
	return 0;
}