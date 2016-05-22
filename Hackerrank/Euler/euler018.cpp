#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)


int sum[15][15];
int main()
{
	int t,n,temp;
	getNum(t);
	while(t--)
	{
		getNum(n);
		f(i,n)
		{
			f(j,i+1)
			{
				getNum(temp);
				if(i==0 && j==0)
				{
					sum[0][0] = temp;
					// printf("sum[%d][%d] = %d\n",i,j,temp);
					continue;
				}
				int upleft_x = i-1;
				int upleft_y = j-1;
				int up_x = i-1;
				int up_y = j;
				int max = 0;
				if(i!=j)
				{
					max = sum[up_x][up_y] + temp;
				}
				if(j!=0)//then upleft is valid
				{
					int m = sum[upleft_x][upleft_y] + temp;
					if(m>max)
						max = m;
				}
				sum[i][j] = max;
				// printf("sum[%d][%d] = %d\n",i,j,max);
			}
		}
		int max = 0;
		f(i,n)
		{
			if(sum[n-1][i] > max)
				max = sum[n-1][i];
		}
		printf("%d\n",max);
	}
	return 0;
}
