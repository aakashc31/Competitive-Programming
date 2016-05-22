#include <bits/stdc++.h>

using namespace std;

#define get(n) inp(n)
#define getcx getchar//_unlocked

inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

bool is_plus_x(int x, int y)
{
	if(y>0 || y&1)
		return false;
	if(x>=y && x<=(1-y))
		return true;
	return false;
} 

bool is_plus_y(int x, int y)
{
	if(x%2==0)
		return false;
	int k = (x-1)/2;
	if(k<0)
		return false;
	if(y>=(-2*k) && y<=(2*k+2))
		return true;
	return false;
}

bool is_minus_x(int x, int y)
{
	if(y&1)
		return false;
	int k = y/2;
	if(k<1)
		return false;
	if(x>=(-2*k) && x<=(2*k-1))
		return true;
	return false;
}

bool is_minus_y(int x, int y)
{
	if(x&1)
		return false;
	int k = (-x)/2;
	if(k<1)
		return false;
	if(y>=(-2*k) && y<=(2*k))
		return true;
	return false;
}

int main()
{
	int t,x,y;
	get(t);
	while(t--)
	{
		get(x),get(y);
		if(is_plus_x(x,y) || is_plus_y(x,y) || is_minus_x(x,y) || is_minus_y(x,y))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}