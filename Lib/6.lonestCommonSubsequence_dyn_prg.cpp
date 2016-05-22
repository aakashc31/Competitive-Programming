
// using dynamic programming O(n^2):
// Time limit exceed ho gaya.. :(

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getStr(s) scanf("%s",&s)

int a1[50000];
int a2[50000];
char A[50001];
char B[50001];
int main()
{
	int m_till_now=0;
	getStr(A);
	getStr(B);
	int l1 = strlen(A);
	int l2 = strlen(B);
	bitset<26> a_alpha;
	bitset<26> b_alpha;
	f(i,l1)
	{
		int tmp = A[i]-'a';
		if(!a_alpha[tmp])
			a_alpha[tmp] = 1;
	}
	f(i,l2)
	{
		int tmp = B[i]-'a';
		if(!b_alpha[tmp])
			b_alpha[tmp] = 1;
	}
	// base case: setting value of a1, that is LCS[i][0] for all i
	bool flag=false; //true if B[0] has been found
	f(i,l1)
	{
		//
		if(flag)
			a1[i]=1;
		else
		{
			if(A[i]==B[0])
			{
				flag = true;
				a1[i]=1;
			}
			else
				a1[i] = 0;
		}
	}
	flag=false; //true if A[0] has been found
	f(j,l2)
	{
		int* anext;
		int* aprev;
		if(j%2 == 0)
		{
			aprev = a2;
			anext = a1;
		}
		else
		{
			aprev = a1;
			anext = a2;
		}
		if(flag)
		{
			if(m_till_now==0) m_till_now=1;
			anext[0] = 1;
		}
		else
		{
			if(A[0]==B[j])
			{
				flag = true;
				anext[0] = 1;
			}
			else
				anext[0] = 0;
		}
		f(i,l1)
		{
			if(A[i]!=B[j])
				anext[i] = max(aprev[i],anext[i-1]);
			else
			{
				anext[i] = aprev[i-1] + 1;
				// printf("%d,%d: %d\n", i, j, anext[i]);
				if(anext[i] > m_till_now)
					m_till_now = anext[i];
			}
		}
	}
	printf("%d\n",m_till_now);

	return 0;
}