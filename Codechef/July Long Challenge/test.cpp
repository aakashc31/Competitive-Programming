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

int result[1010][1010];
int permut[1010];
int cycles[1010][1010];


int fillup(int ar[1010][1010], int q, int m, int offset)
{

	int toFill = 1;
	int l=0;
	while(ar[q][l]!=-1)
	{
		// printf("%d, ",ar[q][l]);
		l++;
	}
	// printf("l = %d\n",l);
	// l is the length of the particular cycle
	result[ar[q][0]][0] = 1 + offset;
	result[ar[q][0]][1] = 2*l + offset;
	result[ar[q][1]][0] = 4 + offset;
	result[ar[q][1]][1] = 2*l - 1 + offset;

	for(int i=2;i<=l-2;i++)
	{
		result[ar[q][i]][0] = result[ar[q][i-1]][0] +1;
		result[ar[q][i]][1] = result[ar[q][i-1]][1] -1;
	}
	result[ar[q][l-1]][0] = 2 + offset;
	result[ar[q][l-1]][1] = 3 + offset;
	toFill = 2*l+1; //this will be filled next
	for(int i=2; i<=m; i++)
	{
		if(i%2==0 || i==3)
		{
			for(int j=l-2; j>=0;j--)
			{
				result[ar[q][j]][i] = toFill + offset;
				toFill++;
			}
			result[ar[q][l-1]][i] = toFill + offset;
			toFill++;
		}
		else
		{
			for(int j=l-1; j>=0;j--)
			{
				result[ar[q][j]][i] = toFill + offset;
				toFill++;
			}
			
		}
	}
	return l*m;
}

int main()
{
	int t;
	getNum(t);
	printf("%d\n",t );
	int nosol = 0;
	while(t--)
	{
		int n,m;
		getNum(n); getNum(m);
		bool flag=false;
		f(i,1010)
		{
			f(j,1010)
				cycles[i][j] = -1;
		}
		f(i,n)
		{
			int temp;
			getNum(temp);
			permut[i] = temp;
			if(i==temp)
				flag = true;
		}
		f(i,n)
		{
			if(permut[permut[i]]==i)
				flag = true;
		}
		if(flag || m<=2 || n<=2)
		{
			printf("No Solution\n");
			nosol++;
			continue;
		}
		bitset<1010> isReached;
		int r=0,c=0;
		f(i,n)
		{
			if(isReached[i])
				continue;
			isReached[i] = 1;
			// printf("%d, ",i);
			cycles[r][c] = i;
			c++;
			int nxt = permut[i];
			while(nxt!=i)
			{
				// printf("%d, ",nxt);
				isReached[nxt] = 1;
				cycles[r][c] = nxt;
				nxt = permut[nxt];
				c++;
			}
			// printf("\n");
			if(c<=2)
				flag = true;
			r++;
			c=0;
		}
		if(flag)
		{
			printf("No Solution\n");
			nosol++;
			continue;
		}
		// printf("Num rows in cycles = %d\n",r);
		// r is the number of different cycles
		int offset=0;
		f(i,r)
		{
			offset = fillup(cycles,i,m,offset);
		}
		printf("%d %d\n",n,m);
		f(i,n)
			printf("%d ",permut[i]);
			printf("\n");
		// printing the answer
		f(i,n)
		{
			f(j,m)
			{
				printf("%d",result[i][j]);
				if(j!=m-1)
					printf(" ");
			}
			printf("\n");
		}
	}
	printf("No sol = %d\n",nosol );
	return 0;
}