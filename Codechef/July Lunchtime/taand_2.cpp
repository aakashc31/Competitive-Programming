#include <bits/stdc++.h>

using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

typedef long long int lli;

int ar[300000];
int bin[300000][35];
int current_indices[300000];
int temp[300000];

int store_in_binary(int a, int i)
{
	int len = 0;
	while(a>0)
	{
		bin[i][len+1] = a%2;
		a/=2;
		len++;
	}
	bin[i][0] = len;
	return len;
}
int getDec(int ar[32], int l)
{
	int ret = 0;
	for(int i=l-1; i>=0; i--)
	{
		ret = (ret<<1) + ar[i];
	}
	return ret;
}
int main()
{
	int n;
	getNum(n);
	int max_len = 0;
	f(i,n) 
	{
		getNum(ar[i]);
		int l = store_in_binary(ar[i],i);
		if(l>max_len)
			max_len = l;
	}
	f(i,n)
	{
		if(bin[i][0]<max_len)
		{
			for(int j=bin[i][0]+1; j<=max_len; j++)
				bin[i][j] = 0;
			bin[i][0] = max_len;
		}
	}
	// 
	// f(i,n)
	// {
	// 	printf("%d\n",ar[i]);
	// 	for(int j=max_len; j>0; j--)
	// 	{
	// 		printf("%d",bin[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// 

	int and_max[32];
	int curr_len = n;
	f(i,n)
		current_indices[i] = i;
	for(int i=max_len; i>0; i--)
	{
		int num1 = 0;
		f(j,curr_len)
		{
			if(bin[current_indices[j]][i]==1)
			{
				temp[num1++] = current_indices[j];
			}
		}
		
		if(num1==0 || num1 == 1)
			and_max[i-1] = 0;
		else
		{
			and_max[i-1] = 1;
			f(j,num1)
			{
				current_indices[j] = temp[j];
			}
			curr_len = num1;
		}
	}
	// f(i,max_len)
	// 	printf("%d ",and_max[i]);
	// printf("\n");
	int ans = getDec(and_max,max_len);
	printf("%d\n",ans);
	return 0;
}