#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define getcx getchar_unlocked
#define getNum(n) inp(n)
#define f(i,n) for(int i=0; i<n; i++)

inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int ar[100000];
int main()
{
	int t,n;
	getNum(t);
	while(t--)
	{
		getNum(n);
		f(i,n)
			getNum(ar[i]);
		sort(ar,ar+n);
		for(int i=2;i<n;i+=2)
			swap(ar[i],ar[i-1]);
		f(i,n)
			printf("%d ",ar[i]);
		printf("\n");
	}

}