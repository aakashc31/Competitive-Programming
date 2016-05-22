#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)

bool isPalindromeInBase(int n, int k)
{
	if(n==0)
		return true;
	char ch[100];
	int len = 0;
	int c = n;
	while(c>0)
	{
		ch[len++] = (c%k) + '0';
		c/=k;
	}
	ch[len] = '\0';
	// printf("%d in base %d = %s\n",n,k,ch);
	int l = 0, r = len-1;
	bool f = true;
	while(l<r)
	{
		if(ch[l]!=ch[r])
			return false;
		l++,r--;
	}
	return true;
}

int main()
{
	int n,k;
	g(n), g(k);
	int s=0;
	f(i,n)
	{
		int t = (isPalindromeInBase(i,10) && isPalindromeInBase(i,k)) ? i:0;
		// printf("%d\n",t);
		s+=t;
	}
	printf("%d\n",s);
	return 0;
}