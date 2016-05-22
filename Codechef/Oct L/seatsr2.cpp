#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
#define g(n) inp(n)
#define getcx getchar//_unlocked
int absl(int i)
{
	if(i<0)
		return -i;
	return i;
}
char s[100005], w[100005];
int dp[100005][205];
int k,a,b;
inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int get(int i, int j)
{
	if(absl(i-j)>k)
		return INT_MAX-200;
	return dp[i][100+i-j];	
}
void __set__(int i,int j, int p)
{
	if(absl(i-j)>k)
		return;
	dp[i][100+i-j] = p;
}

void compute()
{
	int n=  strlen(s), m = strlen(w), low, high;
	// base case

	for(int j=0; j<=k; j++)
		__set__(0,j,j*a), __set__(j,0,j*a);

	for(int i=1; i<=n; i++)
	{
		low = max(i-k,0);
		high = min(m,i+k);
		for(int j=low; j<=high; j++)
		{	
			if(j==0)
				continue;
			int bn = s[i]==w[j]?0:b;
			int t = min(get(i-1,j-1)+bn, get(i-1,j)+a);
			t = min(t, get(i,j-1)+a);
			__set__(i,j,t);
		}
	}
	if(get(n,m) <= k)
		printf("%d\n",get(n,m));
	else
		printf("-1\n");
}



int main()
{
	int t;
	g(t);
	while(t--)
	{
		scanf("%s",s);
		scanf("%s",w);
		g(a),g(b),g(k);
		int m = strlen(s), n = strlen(w);
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		if(b==0)
		{
			int kk = a*(absl(m-n));
			if(kk <= k)
				printf("%d\n",kk);
			else
				printf("-1\n");
			continue;
		}
		compute();
	}
	return 0;
}