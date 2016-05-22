#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)
int T[6100][6100];
char str[6101];

// memoization // gave a TLE
int compute(int i, int j)
{
	if(i==j)
		return 0;
	if(T[i][j]!=-1)
		return T[i][j];
	if(str[i]==str[j])
		return compute(i+1,j-1);
	T[i][j] = 1 + min(compute(i+1,j), compute(i,j-1));
	return T[i][j];
}

int main()
{
	int t;
	g(t);
	while(t--)
	{
		scanf("%s",str);
		int l = strlen(str);
		for(int i=0; i<l; i++) T[i][i] = 0; //base case
		for(int s=1; s<l; s++)
		{
			for(int i = 0; i+s < l; i++)
			{
				if(str[i] == str[i+s])
					T[i][i+s] = T[i+1][i+s-1];
				else
					T[i][i+s] = 1 + min(T[i+1][i+s], T[i][i+s-1]);
			}
		}
		printf("%d\n",T[0][l-1]);
	}
	return 0;
}