#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define test(t) while(t--)
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	int t,n, low, high,temp;
	int B[10000];
	g(t);
	test(t)
	{
		g(n);
		low = high = 0;
		bool flag = true;
		f(i,n) 
		{
			g(B[i]);
			temp = B[i]-1;
			if(temp < 0) temp = 0;
			low += temp;
			high += B[i];
			if(B[i]>100) flag = false;
		}

		if(!flag) printf("NO\n");
		else
		{
			if(100 > low && 100 <= high)
				printf("YES\n");
			else 
				printf("NO\n");
		}
	}
	return 0;
}

/*
	B[i] >=0, <=100
*/