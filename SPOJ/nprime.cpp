#include <bits/stdc++.h>
typedef long long int lli;
lli *pr,np, m = 1299827,n;

bitset<1299828> P;
int main()
{
	P.set();
	np = 0;
	for(lli j = 2; j<=m; j++)
	{
		if(!P[j])
			continue;
		np++;
		lli k = ((lli)(j))*j;
		for( ; k<=m; k+=j)
			P[k] = 0;		
	}
	pr = new lli[np];
	lli index = 0;
	for(lli l=2; l<=m; l++)
	{
		if(P[l])
			pr[index++] = l;
	}
	while(cin>>n)
		printf("%lld\n",pr[n-1]);
	return 0;
}