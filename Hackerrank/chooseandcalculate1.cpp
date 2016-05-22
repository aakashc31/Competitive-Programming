
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define getLong(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0;i<n;i++)
typedef long long int lli;
const int modulo = 1000000007;


int ar[100001];
int table[10000][10000]
map<pair<int,int>, int> temp_table;

int ncr_mod(int n, int r)
{
	if(r>n)
		return 0;
	if(r > n-r)
		r = n-r;
	if(r==0)
		return 1;
	else if(r==1)
		return n;
	else if(n==r)
		return 1;
	if(n<10000)
		table[n][r]
	pair<int,int> p(n,r);
	if(table.find(p) != table.end())
	{
		return table.find(p)->second;
	}
	else
	{
		int a = ncr_mod(n-1,r);
		int b = ncr_mod(n-1,r-1);
		b = (a+b)%modulo;
		table[p] = b;
		return b;
	}
}


int main()
{
	int n,k;
	getNum(n), getNum(k);
	f(i,n)
		getNum(ar[i+1]);
	// input over
	sort(ar+1,ar+n+1);
	// array has been sorted.
	lli s = 0;
	for(int i=1; i<=n+k-1; i++)
	{
		for(int x = k-1; x<=n-i; x++)
		{
			int tmp = (ar[i+x]-ar[i])%modulo;
			lli cmb = ncr_mod(x-1,k-2); //C(x-1,k-2)%modulo
			cmb = (cmb*tmp)%modulo;
			s = (s + cmb)%modulo;
		}
	}
	printf("%lld\n",s);
	return 0;
}