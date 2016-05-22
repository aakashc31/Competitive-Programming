#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(lli i=0 ;i<n; i++)

lli fact(lli n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}




// stores the number stored in ch in ar in little endian form, and if size is less than "size", then fills zeroes at the end
// eg: ch="123", size=5; ar will have {3,2,1,0,0} after exec
void store_string(char ch[], int ar[], int size)
{
	int l = strlen(ch);
	int len = l;
	int i=0;
	while(l>0)
	{
		ar[i] = ch[l-1] - '0';
		i++, l--;
	}
	while(len<size)
		ar[len++] = 0;
}

// prints integer represented by ar, assuming little endian form, and max size of l
void print_array(int ar[], int l)
{
	while(ar[l]==0)
		l--;
	while(l>=0)
		printf("%d",ar[l]), l--;
	printf("\n");
}

void add_arrays(int a[], int b[], int s[], int size)
{
	int carry = 0;
	f(i,size)
	{
		int temp = a[i] + b[i] + carry;
		s[i] = temp%10;
		carry = temp/10;
	}
}

void subtract(int a[], int b[], int d[], int size)
{
	int carry = 0;
	f(i,size)
	{
		int diff = a[i] - b[i] - carry;
		if(diff < 0)
		{
			diff+=10;
			carry = 1;
			d[i] = diff;
		}
		else
		{
			d[i] = diff;
			carry = 0;
		}
	}
}

void multiply_by_const(int ar[], int size, int num)
{
	int carry = 0;
	f(i,size)
	{
		int t = ar[i]*num + carry;
		ar[i] = t%10;
		carry=t/10;
	}
}


