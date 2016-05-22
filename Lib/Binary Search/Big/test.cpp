#include "BigNum.h"
#include <cstdio>
typedef long long int lli;

#define f(i,n) for(int i=0; i<n; i++)



int main()
{
	
	// char ch[1000];
	// scanf("%s",ch);
	// char ch[] = "33";
	BigNum *b = new BigNum("33");
	// c.printNum();
	BigNum *c = new BigNum("45");
	// c->printNum();
	// b->add(c);
	// b->subtract(c);
	// b->printNum();
	// BigNum *pdt = shift_multiply(b,5,2);
	// BigNum* pdt = c->multiply(b);
	// BigNum* pdt = power(b,4);
	BigNum* pdt = subtractBig(c,b);
	pdt->printNum();
	// b->printNum();
	// a.printNum();
	return 0;
}