#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)
int dp[2000][2000];
int v[2000];
int compute(int i, int j, int age)
{
	if(i==j)
		return age*v[i];
	if(i>j) return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j] = max(compute(i+1,j,age+1)+age*v[i], compute(i,j-1,age+1)+age*v[j]);
	return dp[i][j];
}
int main()
{
	int n; g(n);
	f(i,n) g(v[i]);
	f(i,n){f(j,n) dp[i][j]=-1;}
	printf("%d\n", compute(0,n-1,1));
	return 0;
}