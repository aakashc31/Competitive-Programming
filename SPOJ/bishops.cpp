#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0;i<n;i++)
char ch[110];

void doublear(int ar[], int l)
{
	l--;
	int carry=0;
	while(l>=0)
	{

		int k = ar[l];
		k*=2;
		k+=carry;
		// printf("l = %d\nk = %d\n",l,k);
		ar[l] = k%10;
		carry = k/10;
		l--;
	}
}

void decby2(int ar[], int l)
{
	l--;
	if(ar[l]>=2)
		ar[l]-=2;
	else
	{
		int i = l-1;
		ar[i]--;
		ar[l]+=8;
		while(ar[i]<0)
		{
			ar[i]+=10;
			ar[i-1]--;
			i--;
		}
	}
}

void print(int ar[], int l)
{
	int i=0;
	while(ar[i]==0)
		i++;
	while(i<l)
	{
		printf("%d",ar[i]);
		i++;
	}
	printf("\n");
}
int main()
{
	while(cin>>ch)
	{
		int l = strlen(ch);
		if(l==1 && ch[0]=='1')
		{
			printf("1\n");
			continue;
		}
		int ar[l+1];
		f(i,l)
		{
			ar[i+1] = ch[i] - '0';
		}
		ar[0] = 0;
		// print(ar,l+1);
		doublear(ar,l+1);
		// print(ar,l+1);
		decby2(ar,l+1);
		print(ar,l+1);
	}
	return 0;
}