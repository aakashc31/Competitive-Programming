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
int ar[1010]; //stores the permutation
int cycles[1010][1010];

int fill_up(int q, int m, int offset)
{
	int toFill = 1;
	int l=0;
	while(cycles[q][l]!=-1)
		l++;
	// l is the length of the particular cycle
	result[cycles[q][0]][0] = 1 + offset;
	result[cycles[q][0]][1] = 2*l + offset;
	result[cycles[q][1]][0] = 4 + offset;
	result[cycles[q][1]][1] = 2*l - 1 + offset;

	for(int i=2;i<=l-2;i++)
	{
		result[cycles[q][i]][0] = result[cycles[q][i-1]][0] +1;
		result[cycles[q][i]][1] = result[cycles[q][i-1]][1] -1;
	}
	result[cycles[q][l-1]][0] = 2 + offset;
	result[cycles[q][l-1]][1] = 3 + offset;
	toFill = 2*l+1; //this will be filled next
	for(int i=2; i<=m; i++)
	{
		if(i%2==0 || i==3)
		{
			for(int j=l-2; j>=0;j--)
			{
				result[cycles[q][j]][i] = toFill + offset;
				toFill++;
			}
			result[cycles[q][l-1]][i] = toFill + offset;
			toFill++;
		}
		else
		{
			for(int j=l-1; j>=0;j--)
			{
				result[cycles[q][j]][i] = toFill + offset;
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
	while(t--)
	{
		// clearing the results array
		f(i,1010)
		{
			f(j,1010)
				result[i][j] = -1;
		}

		int n,m;
		getNum(n);getNum(m);
		f(i,n)
			getNum(ar[i]);
		// input over.
		if(m<=2)
		{
			printf("No Solution\n");
			continue;
		}

		// computing cycles
		bool flag = false; //becomes true iff any cycle length is leq 2
		bitset<1010> isReached;
		int r=0,c=0;
		f(i,n)
		{
			if(isReached[i])
				continue;
			isReached[i] = 1;
			int next = ar[i];
			c=0;
			cycles[r][c] = i;
			c++;
			while(next!=i)
			{
				isReached[next] = 1;
				cycles[r][c] = next;
				c++;
				next = ar[next]; 
			}
			// c is the cycle length
			r++;
			if(c<=2)
			{
				flag = true;
				break;
			}
		}

		// all the cycles have been stored in cycles array
		if(flag)
		{
			printf("No Solution\n");
			continue;
		}

		// now fill the results array.
		// r is the number of distinct cycles
		int offset = 0;
		f(i,r)
		{
			offset = fill_up(i,m,offset);
		}
		// now that solution exists, print the results array
		f(i,n)
		{
			f(j,m)
			{
				printf("%d ",result[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}