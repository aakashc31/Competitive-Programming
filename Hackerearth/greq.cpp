#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define getNum(n) scanf("%lld",&n)
#define f(i,n) for(lli i=0; i<n; i++)

typedef long long int lli;

lli ar[1500];

int main()
{
	lli n,q,a,b;
	getNum(n);
	f(i,n)
		getNum(ar[i]);
	getNum(q);
	while(q--)
	{
		getNum(a), getNum(b);
		a--,b--;
		lli l = b-a+1;
		lli temp_ar[b-a+1];
		f(i,l)
			temp_ar[i] = ar[a+i];
		sort(temp_ar,temp_ar+l);
		if(l%2==1)
		printf("%lld\n",temp_ar[l/2]);
		else
			printf("%lld\n",temp_ar[(l/2)-1]);
	}
	return 0;
}