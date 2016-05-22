#ifndef __BIGNUM__
#define __BIGNUM__ 10
typedef long long int lli;
#define SIZE 1000000
// #define f(i,n) for(int i=0; i<n; i++)
class BigNum
{
public:
	int ar[SIZE];
	int length;
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
BigNum* shift_multiply(BigNum* a, lli b, int shift); //
BigNum* power(BigNum* x, int a);

BigNum* addBig(BigNum* a, BigNum* b);
BigNum* subtractBig(BigNum* a, BigNum* b);
BigNum* multiplyBig(BigNum* a, BigNum* b);
#endif