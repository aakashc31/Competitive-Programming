#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
typedef long long int lli;


// returns sqrt if perfect square, -1 o.w.
lli root(lli i)
{
	if(i<0)
		return -1;
	lli t = sqrt(i);
	if(t*t == i)
		return t;
	else 
		return -1;
}


int main()
{
	lli n;
	cin>>n;
	while(n!=-1)
	{
		lli disc = root(12*(4*n-1));
		if(disc==-1)
			printf("N\n");
		else
		{
			if(((6+disc)%12)==0)
				printf("Y\n");
			else
				printf("N\n");
		}
		cin >> n;
	}
	return 0;
}