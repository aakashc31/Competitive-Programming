#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define g(n) scanf("%d",&n)
// int comp[4];

// int pow(int n, int p)
// {
// 	int s = 1;
// 	f(i,p) s*=n;
// 	return s;
// }

// bool isValid(int n, int k)
// {
// 	int temp = n,s=0;
// 	while(n>0)
// 	{
// 		s += pow(n%10,k);
// 		n/=10;
// 	}
// 	return temp==s;
// }

// void init()
// {
// 	f(i,4) comp[i] = 0;
// 	for(int i=10; i<= 10000000; i++)
// 	{
// 		f(j,4)
// 		{
// 			if(isValid(i,j+3))
// 				comp[j]+=i;
// 		}
// 	}

// }
int main()
{
	// init();
	// printf("Yo\n");
	// f(i,4) printf("%d\n",comp[i]);
	int comp[] = {1301,19316,443839,548834};
	int n;
	g(n);
	printf("%d\n", comp[n-3]);
	return 0;
}