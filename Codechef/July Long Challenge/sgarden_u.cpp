#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)
#define modulo 1000000007;


int factors[100001];
int ar[100001];

void factorize(int n)
{
	int s=0;
	while(n%2==0)
	{
		s++;
		n /=2;
	}
	if(s>factors[2])
		factors[2] = s;

	for (int i = 3; i <= sqrt(n); i = i+2)
    {
    	s=0;
        while (n%i == 0)
        {
            s++;
            n /=i;
        }
        if(factors[i]<s)
        	factors[i]=s;
    }
 
    if (n > 2 && factors[n]==0)
        factors[n]=1;
}

int findlcm(int n)
{
	int ans = 1;
	for(int i=2;i<=n;i++)
	{
		long long int p = pow(i,factors[i]);
		p = (p%1000000007)*(ans);
		ans = (p%1000000007);
	}
	return ans;
}

int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		int g = 1;

		long long int ans = 1;
		bitset<100001> iscalc;
		bitset<100001> chain_length;
		int u = 0, max=0;
		getNum(n);
		f(i,n)
		{
			getNum(ar[i+1]);
			factors[i+1] = 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(iscalc[i])
				continue;
			iscalc[i] = 1;
			int pr = ar[i];
			int t = 1;
			while(pr!=i)
			{
				iscalc[i] = 1;
				t++;
				pr = ar[pr];
			}
			if(!chain_length[t])
			{
				chain_length[t]=1;
				factorize(t);
			}
		}
		
		printf("%d\n",findlcm(n));
	}
	return 0;

}
