#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include "BigNum.h"

#define f(i,n) for(int i=0; i<n; i++)
#define fab(i,a,b) for(int i=a;i<=b;i++)
typedef long long int lli;

using namespace std;

BigNum::BigNum()
{
	// ar = (int*)(malloc(SIZE*4));
	f(i,SIZE)
		ar[i] = 0;
	length = 0;
	neg = false;
}

BigNum::BigNum(char* ch)
{
	// ar = new int[SIZE];
	int l = strlen(ch);
	f(i,l)
	{
		ar[i] = ch[l-1-i]-'0';
	}
	length = l;
	fab(i,length,SIZE-1)
		ar[i] = 0; 
}

BigNum::BigNum(lli n)
{
	// ar = new int[SIZE];
	length=0;
	while(n>0)
	{
		ar[length++] = n%10;
		n/=10;
	}
	fab(i,length,SIZE-1)
		ar[i] = 0;
}

void BigNum::copy(BigNum* b)
{
	f(i,SIZE)
		ar[i] = b->ar[i];
	length = b->length;

}

void BigNum::printNum()
{
	f(i,length)
	{
		printf("%d",ar[length-1-i]);
	}
	printf("\n");
}


//Assumption: Size will not exceed.
void BigNum::add(BigNum* b)
{
	int carry = 0;
	f(i,SIZE)
	{
		int temp = ar[i] + b->ar[i] + carry;
		ar[i] = temp%10;
		carry = temp/10;
	}
	int l = max(length, b->length);
	if(ar[l]==0)
		length = l;
	else
		length = l+1;

}

bool BigNum::isNegative()
{
	return neg;
}

bool BigNum::isEqual(BigNum* b)
{
	if(length!=b->length)
		return false;
	else
	{
		f(i,length)
		{
			if(ar[i]!=b->ar[i])
				return false;
		}
		return true;
	}
}

bool BigNum::isLessThan(BigNum* b)
{
	if(length < b->length)
		return true;
	else if(length > b->length)
		return false;
	else
	{
		for(int i=length-1; i>=0; i++)
		{
			if(ar[i] < b->ar[i])
				return true;
			else if(ar[i] >  b->ar[i])
				return false;
		}
		return false;
	}
}

bool BigNum::isGreaterThan(BigNum* b)
{
	if(length > b->length)
		return true;
	else if(length < b->length)
		return false;
	else
	{
		for(int i=length-1; i>=0; i++)
		{
			if(ar[i] > b->ar[i])
				return true;
			else if(ar[i] <  b->ar[i])
				return false;
		}
		return false;
	}
}

void BigNum::multiply(lli a)
{
	lli carry = 0;
	f(i,length)
	{
		lli temp = ar[i]*a + carry;
		ar[i] = temp%10;
		carry = temp/10;
	}
	while(carry>0)
	{
		ar[length++] = carry%10;
		carry/=10;
	}
}

void BigNum::subtract(BigNum* b)
{
	if(isLessThan(b))
	{
		printf("Subtraction Failed...\n");
		return;
	}
	int carry = 0;
	f(i,length)
	{
		lli temp = ar[i] - b->ar[i] - carry;
		if(temp < 0)
		{
			temp+=10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		ar[i] = temp;
	}
	
	while(ar[length-1]==0)
		length--;
}

void BigNum::updateLength()
{
	int i;
	for(i=SIZE-1; i>=0; i--)
	{
		if(ar[i]!=0)
			break;
	}
	if(i==-1)
		length = 0;
	else
		length = i+1;
}

// grade school algorithm.
BigNum* BigNum::multiply(BigNum* b)
{
	BigNum* res = new BigNum();
	f(i,length)
	{
		res->add(shift_multiply(b,ar[i],i));
	}
	return res;
}

// multiplies a by number b, and shifts it by shift. eg. (33,5,2) -> 16500. Does not affect a.
BigNum* shift_multiply(BigNum* a, lli b, int shift)
{
	BigNum* res = new BigNum();
	res->length = shift;
	lli carry = 0;
	f(i,a->length)
	{
		lli temp = a->ar[i]*b + carry;
		res->ar[(res->length)++] = temp%10;
		carry = temp/10;
	}
	while(carry>0)
	{
		res->ar[res->length] = carry%10;
		res->length = res->length + 1;
		carry/=10;
	}
	return res;
} 

BigNum* power(BigNum* x,int i)
{
	if(i==0)
	{
		BigNum* temp = new BigNum(1);
		return temp;
	}
	else if(i%2==0)
	{
		BigNum* temp = power(x,i/2);
		temp = temp->multiply(temp);
		return temp;
	}
	else
	{
		BigNum* temp = power(x,i/2);
		temp = temp->multiply(temp);
		temp = temp->multiply(x);
		return temp;
	}
}


BigNum* addBig(BigNum* a, BigNum* b)
{
	BigNum* temp = new BigNum();
	temp->copy(a);
	temp->add(b);
	return temp;
}

BigNum* subtractBig(BigNum* a, BigNum* b)
{
	BigNum* temp = new BigNum();
	// a->printNum();
	temp->copy(a);
	// temp->printNum();
	temp->subtract(b);
	// temp->printNum();
	return temp;
}

BigNum* multiplyBig(BigNum* a, BigNum* b)
{
	BigNum* res = new BigNum();
	f(i,a->length)
	{
		res->add(shift_multiply(b,a->ar[i],i));
	}
	return res;
}
