#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

struct id
{
	int ar[6];
};

bool comparator(const id& a, const id& b)
{
	f(i,5)
	{
		if(a.ar[i] != b.ar[i])
			return a.ar[i] < b.ar[i];
	}
	return a.ar[5] < b.ar[5];
}

id accounts[100000];
void print(id a, int c)
{
	printf("%.2d ",a.ar[0]);
	printf("%.8d ",a.ar[1]);
	fab(i,2,5) printf("%.4d ",a.ar[i]);
	printf("%d\n",c);
}
bool operator==(const id&a, const id& b)
{
	f(i,6)
	{
		if(a.ar[i] != b.ar[i])
			return false;
	}
	return true;
}
int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n)
		{
			id k;
			f(j,6) g(k.ar[j]);
			accounts[i] = k;
		}
		sort(accounts, accounts+n, comparator);
		id p = accounts[0]; int c = 1;
		fab(i,1,n-1)
		{
			if(accounts[i]==accounts[i-1])
				c++;
			else
			{
				print(p,c);
				c = 1, p = accounts[i];
			}
		}
		print(p,c);
		printf("\n");
	}
	return 0;
}