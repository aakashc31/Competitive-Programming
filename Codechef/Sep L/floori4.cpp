#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define f(i,n) for(lli i=0; i<n; i++)
#define g(n) scanf("%lld",&n)


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
lli sum(lli n, lli m)
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

lli s_range(lli a, lli b, lli m)
{
	return (( sum(b,m) + ( ((m-1)*sum(a-1,m))%m) )%m);
}

lli power_mod_4(lli n, lli m)
{
	lli s = n*n*n;
	s %= m;
	s = (s*n)%m;
	return s;
}
int main()
{
	lli t,n,m;
	g(t);
	while(t--)
	{
		g(n), g(m);
		lli root = lli(sqrt(double(n)));
		// printf("%lld\n",root );
		lli s = 0;
		f(i,root)
		{
			lli temp = i+1;
			s = s+ (power_mod_4(temp,m)*(n/temp))%m;
			s%=m;
			printf("%lld\n",s);
			// printf("Yo\n");
		}
		lli den = 1, ub = n, lb = n/2;
		while(true)
		{
			// printf("%lld\n",den );
			ub = n/den;
			lb = (n/(den+1))+1;
			if(lb <= root)
			{
				lb = root+1;
				s = s+ (den*s_range(lb,ub,m))%m;
				s%=m;
				printf("%lld\n",s);
				break;
			}
			else
			{
				s = s+ (den*s_range(lb,ub,m))%m;
				s%=m;
			}
			printf("%lld\n",s);
			den++;
		}
		printf("%lld\n",s);
	}

}