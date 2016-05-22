#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define g(n) scanf("%d",&n)

char ch[1010][1010];
int row[1000];
int col[1000];

int main()
{
	int t,n;
	g(t);
	while(t--)
	{
		g(n);
		f(i,n) scanf("%s",ch[i]),row[i]=-1,col[i]=-1;
		f(i,n)
		{
			f(j,n)
			{
				if(ch[i][j]=='#')
					row[i] = j;
				if(ch[j][i] == '#') //ith column, jth row
					col[i] = j;
			}
		}
		// f(i,n)
		// {
		// 	printf("row[%d] = %d, ",i,row[i]);
		// }
		// printf("\n");
		// f(i,n)
		// {
		// 	printf("col[%d] = %d, ",i,col[i]);
		// }
		// printf("\n");
		int s=0;
		f(i,n)
		{
			f(j,n)
			{
				if(ch[i][j]=='.' && row[i]<j && col[j]<i)
				{
					s++;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}