#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0 ;i<n; i++)




// stores the number stored in ch in ar in little endian form, and if size is less than "size", then fills zeroes at the end
// eg: ch="123", size=5; ar will have {3,2,1,0,0} after exec
// void store_string(char ch[], lli ar[], lli size)
// {
// 	lli l = strlen(ch);
// 	lli len = l;
// 	lli i=0;
// 	while(l>0)
// 	{
// 		ar[i] = ch[l-1] - '0';
// 		i++, l--;
// 	}
// 	while(len<size)
// 		ar[len++] = 0;
// }

// prints integer represented by ar, assuming little endian form, and max size of l
void print_array(lli ar[], lli l)
{
	while(ar[l]==0)
		l--;
	while(l>=0)
		printf("%d",ar[l]), l--;
	printf("\n");
}

void add_arrays(lli a[], lli b[], lli s[], lli size)
{
	lli carry = 0;
	f(i,size)
	{
		lli temp = a[i] + b[i] + carry;
		s[i] = temp%10;
		carry = temp/10;
	}
}

void subtract(lli a[], lli b[], lli d[], lli size)
{
	lli carry = 0;
	f(i,size)
	{
		lli diff = a[i] - b[i] - carry;
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

void multiply_by_const(lli ar[], lli size, lli num)
{
	lli carry = 0;
	f(i,size)
	{
		lli t = ar[i]*num + carry;
		ar[i] = t%10;
		carry=t/10;
	}
}

void divide_by_3(lli ar[], lli size)
{
	lli carry = 0;
	f(i,size)
	{
		lli temp = (ar[size-i-1]+carry*10);
		ar[size-i-1] = temp/3;
		carry = temp%3;
	}
}

void divide_by_10(lli ar[], lli size)
{
	f(i,size-1)
		ar[i] = ar[i+1];
	ar[size-1] = 0;
}

lli modulo(lli ar[], lli size, lli m)
{
	if(size==1)
		return ar[0]%m;
	lli temp = (modulo(ar+1,size-1,m));
	temp*=10;
	temp = (ar[0] + temp)%m;
	return lli(temp);
}

void store_string(lli num, lli ar[], lli size)
{
	lli i=0;
	while(num>0)
	{
		ar[i++] = num%10;
		num/=10;
	}
	while(i<size)
		ar[i++] = 0;
}
//summnation i^4 from 1 to n, modulo m
lli sum_fourth_power(lli n, lli m)
{
	lli ar[60];
	store_string(3*n,ar,60);

	multiply_by_const(ar,60,n); //3*n*n

	lli br[60];
	store_string((3*n-1),br,60);

	lli cr[60];
	add_arrays(ar,br,cr,60); //cr = 3n^2 + 3n -1 
	multiply_by_const(cr,60,n);
	multiply_by_const(cr,60,2*n+1);
	multiply_by_const(cr,60,n+1);
	divide_by_10(cr,60);
	divide_by_3(cr,60);


	return modulo(cr,60,m);
}
int main()
{
	// char ch[] = "985320";
	// int ar[10];
	// int size = 10;
	// store_string(ch,ar,10);
	// print_array(ar,size-1);
	// divide_by_10(ar,size);
	// print_array(ar,size-1);
	// printf("%d\n",modulo(ar,10,1119));
	// sum_fourth_power(10000000000,11);
	while(true)
	{
		lli n,m;
		scanf("%lld",&n);
		scanf("%lld",&m);
		printf("%lld\n",sum_fourth_power(n,m));

	}
	
	return 0;
}

