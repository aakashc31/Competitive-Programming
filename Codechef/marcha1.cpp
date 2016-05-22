//space nahi hai utna
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
	int t;
	getNum(t);
	while(t-- > 0)
	{
		int n,m;
		getNum(n);
		getNum(m);
		int ar[n];
		f(i,n)
			getNum(ar[i]);
		sort(ar,ar+n);
		int p = pow(float(2),float(n));
		short int subsetsum[p];
		int pointer=1;
		subsetsum[0] = 0;
		int flag = 0;
		f(i,n)
		{
			f(j,pointer)
			{
				int s = subsetsum[j]+ar[i];
				subsetsum[pointer+j] = s;
				// cout << "subsetsum at " << pointer+j <<" = "<<s << endl;
				if(s == m)
				{
					cout << "yes" <<endl;
					flag = 1;
				}
			}
			pointer *= 2; 
		}
		if(flag ==0 )
			cout << "no" <<endl;
	}
	return 0;
}