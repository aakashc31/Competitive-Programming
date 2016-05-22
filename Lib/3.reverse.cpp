#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)



int reverse_num(int n)
{
	int k = 0;
	while(n)
	{
		int d = n%10;
		n/=10;
		k = k*10 + d;
	}
	return k;
}

// reverses the character array from l to r both inclusive
void reverse_string(char ch[], int l, int r)
{
	while(l<=r)
	{
		char t = ch[l];
		ch[l] = ch[r];
		ch[r] = t;
		l++,r--;
	}
}

int main()
{
	char ch[] = "Aakash";
	reverse_string(ch,1,5);
	printf("%s\n",ch);
	return 0;
}