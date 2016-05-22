#include <bits/stdc++.h>

#define getNum(n) scanf("%d",&n)
#define f(i,n) for(int i=0; i<n; i++)

const int size = 5000001;
typedef long long int lli;

int ar[size];

int compute(lli i)
{
	if(i>=size)
	{
		int s = 1;
		if(i&1)
			s=compute(3*i+1)+1;
		else
			s=compute(i/2)+1;
		return s;
	}
	else if(ar[i]!=-1)
		return ar[i];
	else if(i&1)
	{
		ar[i] = 1+compute(3*i+1);
		return ar[i];
	}
	else
	{
		ar[i] = 1+compute(i/2);
		return ar[i];
	}
	return -1;
}

int main()
{
	f(i,size) ar[i]=-1;
	ar[1] = 1;
	for(lli i=2;i<size;i++)
	{
		if(ar[i]==-1)
			compute(i);
	}
	// printf("%d \n",ar[size-2]);
	lli max_till_now = ar[0];
	lli max_ind = 0;
	for(lli i=1;i<size;i++)
	{
		if(ar[i]>=max_till_now)
		{
			
			max_till_now = ar[i];
			ar[i] = i;
			max_ind = i;
		}
		else
		{
			ar[i] = max_ind;
		}
	}
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		printf("%d\n",ar[n]);
	}
	return 0;
}