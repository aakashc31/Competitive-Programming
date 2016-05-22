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

map<pair<int,int>, int> M;


int gcd(int a, int b)
{
	if(a<b)
		return gcd(b,a);
	if(a%b==0)
		return b;
	else 
	{
		pair<int,int> p(a,b);
		if(M.find(p)!=M.end())
			return M.find(p)->second;
		int k  = gcd(b,a%b);
		M[p] = k;
		return k;
	}
}

long long int lcm(long long int a, long long int b)
{
	long long int g = gcd(a,b);
	if(g<=0)
		return 1;
	a = a/g;
	long long int pd = a*b;
	return pd;
}


long long int printlcm(int arr[], int l, int r)
{
	// long long int ans = 1;//lcm_ar(ar,l,r);
	if(l<0 || l>r || r<0 || r>100000 || l>100000)
		return 1;
	if(l==r)
		return arr[l];
	else if(l==r-1)
		return lcm(arr[l],arr[l+1]);
	else
	{
		long long int lhalf = printlcm(arr,l,(l+r)/2);
		long long int rhalf = printlcm(arr,(l+r)/2+1,r);
		return lcm(lhalf,rhalf);
	}
}

int ar[100001];

int u[100001];
int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		bitset<100001> iscalc;
		getNum(n);
		long long int lcomp = 1;
		int uind = 0;
		f(i,n)
			getNum(ar[i+1]);

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
			u[uind] = t;
			uind++;
			// printf("%lld %d\n",lcomp,t);
			// if(uind==1)
			// 	lcomp = t;
			// else
			// 	{

			// 		if(lcomp%t!=0)
			// 		{

			// 			lcomp = lcm(lcomp,t);
			// 		}
			// 	}
		}
		int modulo = 1000000007;
		// printlcm(num,1,n);
		printf("%d\n",lcomp%(1000000007));
		// // vector::iterator it = unique_copy(num+1,num+n+1,uniq.begin());
		// printf("%d\n",printlcm(u,0,uind-1)%modulo);

	}
	return 0;

}