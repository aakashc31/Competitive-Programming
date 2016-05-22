#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
#include <conio.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define fab(a,b) for(int i=a;i<=b;i++)
#define getNum(n) scanf("%d",&n)

int result[1000][1000];
int permut[1000];


void check(int ith, int jth, int m)
{
	int s=0;
	f(i,m)
	{
		f(j,m)
		{
			if(result[ith][i] > result[jth][j])
				s++;
		}
	}
	double prob = double(s)/(m*m);
	if(prob>0.5){
		// printf("True for %d, %d  . s is %d\n",ith,jth,s);
	}
	else 
		printf("False for %d, %d  . s is %d\n",ith,jth,s);
}
int main()
{
	int t;
	getNum(t);
	while(t--)
	{
		int n,m;
		getNum(n);
		getNum(m);
		f(i,n)
			getNum(permut[i]);
		f(i,n)
		{
			f(j,m)
			{
				getNum(result[i][j]);
			}
		}

		f(i,n)
		{
			check(i,permut[i],m);
		}
		printf("Done");
		// getch();
	}
	return 0;
}