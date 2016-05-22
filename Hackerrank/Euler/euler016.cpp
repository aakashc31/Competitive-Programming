#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

#define SIZE 1000000
#define f(i,n) for(lli i=0; i<n; i++)
#define fab(i,a,b) for(lli i=a;i<=b;i++)
#define getNum(n) scanf("%lld",&n)

typedef long long int lli;


using namespace std;

class BigNum
{
public:
	lli ar[SIZE];
	lli length;
	bool neg;
	BigNum(); //initialize to zero
	BigNum(char* ch); //store the number represented by ch in the current object
	BigNum(long long int a); //store the number in object
	void add(BigNum* a); //adds a to this
	void subtract(BigNum* b); //
	BigNum* multiply(BigNum* b); //
	void multiply(long long int a); //multiply this object by constant
	void printNum(); //
	bool isEqual(BigNum* b); //
	bool isNegative(); //
	bool isLessThan(BigNum* b); //
	bool isGreaterThan(BigNum* b); //
	void updateLength(); //
	void copy(BigNum* b); //
};
BigNum* shift_multiply(BigNum* a, lli b, lli shift); 
BigNum* power(BigNum* x, lli a);
// Begin..... definitions of functions for BigNum

BigNum::BigNum()
{
	// ar = (lli*)(malloc(SIZE*4));
	f(i,SIZE)
		ar[i] = 0;
	length = 0;
	neg = false;
}

BigNum::BigNum(char* ch)
{
	// ar = new lli[SIZE];
	lli l = strlen(ch);
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
	// ar = new lli[SIZE];
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
}

void BigNum::printNum()
{
	f(i,length)
	{
		printf("%lld",ar[length-1-i]);
	}
	printf("\n");
}


//Assumption: Size will not exceed.
void BigNum::add(BigNum* b)
{
	lli carry = 0;
	f(i,SIZE)
	{
		lli temp = ar[i] + b->ar[i] + carry;
		ar[i] = temp%10;
		carry = temp/10;
	}
	lli l = max(length, b->length);
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
		for(lli i=length-1; i>=0; i++)
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
		for(lli i=length-1; i>=0; i++)
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
	// printf("%lld\n",length);
	lli carry = 0;

	f(i,length)
	{
		// printf("Here\n");
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
	lli carry = 0;
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
	lli i;
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
BigNum* shift_multiply(BigNum* a, lli b, lli shift)
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

BigNum* power(BigNum* x,lli i)
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

//End... definitions for functions ends here...
lli sumDig(lli s)
{
	lli sum = 0;
	while(s>0)
	{
		sum+=(s%10);
		s/=10;
	}
	return sum;
}
int main()
{
	lli t,n;
	getNum(t);
	// t = 100;
	BigNum* b;
	while(t--)
	{
		getNum(n);
		// n = 10000;
		if(n<=30)
		{
			lli s = pow(2,n);
			printf("%lld\n",sumDig(s));
			continue;
		}
		b = new BigNum(1);
		
		lli radix = 20;
		lli q = n/radix;
		lli r = n%radix;
		lli maxpow = pow(2,radix);
		// printf("Max Pow = %lld\n",maxpow );
		lli rem = pow(2,r);
		// printf("Rem Pow = %lld\n",rem );
		// printf("Yo I am here\n");
		f(i,q)
			b->multiply(maxpow);
		// printf("I am out\n");
		b->multiply(rem);

		lli sum = 0;
		f(i,b->length)
		{
			sum+=b->ar[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
