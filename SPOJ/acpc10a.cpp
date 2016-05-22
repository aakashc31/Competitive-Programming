#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int main()
{
	int a,b,c;
	getNum(a),getNum(b),getNum(c);
	while(a!=0 || b!=0 || c!=0)
	{
		if(a+c == 2*b)
		{
			printf("AP %d\n",2*c-b);
		}
		else
		{
			printf("GP %d\n",(c*c)/b);
		}
		getNum(a),getNum(b),getNum(c);
	}
	return 0;
}