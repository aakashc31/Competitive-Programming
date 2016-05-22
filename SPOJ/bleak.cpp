#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
int ar[1000000];

bool isSupported(int i)
{
	int k = __builtin_popcount(i);
	if(i<0)
		return false;
	if(i<=1)
		return true;
}


bool isBleak(int m)
    {
       int k = __builtin_popcount(m);
       for(int i=1; i<=k; i++)
       {
          if(__builtin_popcount(m-i) == i)
              return false;
       }
       return true;
    }
    
// bool isBleak(int m)
// {
// 	int k = __builtin_popcount(m);
// 	for(int i=1; i<=k; i++)
// 	{
// 		if(__builtin_popcount(m-i) == i)
// 			return false;
// 	}
// 	return true;
// }

int main()
{
	int n;
	// int size = 1000000;
	// memset(ar,0,sizeof ar);
	// for(int i=1; i<size; i++)
	// {
	// 	int k = __builtin_popcount(i);
	// 	if (i+k < size)
	// 	{
	// 		ar[i+k] = i;
	// 	}
	// }
	// printf("Bleak numbers: \n\n");
	// f(i,size)
	// {
	// 	if(ar[i]==0)
	// 		printf("%d\n",i);
	// }
	while(cin>>n)
	{
		if(isBleak(n))
			printf("Bleak\n");
		else
			printf("Not Bleak\n");
	}
	return 0;
}