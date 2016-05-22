#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)

struct tup{
	int a,b,c,d,s;
};
// tup make_tup(int x, )
// {
// 	tup k;
// 	k.a = x, k.b = y, k.c = z, k.d = w;
// 	k.s = x+y+z+w;
// 	printf("%d\n",k.s);
// 	return k;
// }
bool comp(const tup& x, const tup& y)
{
	return (x.s < y.s);
}
int main()
{
	tup ar[64];
	int ind = 0;
	int n=4;
	int i,j,k,l;
	i=0;
	while(i<4)
	{
		j=0;
		while(j<4)
		{
			k=0;
			while(k<4)
			{
				l=0;
				while(l<4)
				{
					// ar[ind].a = i, ar[ind].b = j, ar[ind].c = k, ar[ind].d = l;
					// ar[ind].s = i+j+k+l;
					// // ind++;
					// // printf("%d\n",ind);
					// printf("%d - {%d,%d,%d,%d} = %d,\n",ind,ar[ind].a,ar[ind].b,ar[ind].c,ar[ind].d,ar[ind].s);
					// ind++;
					// l++;
					printf("%d,%d,%d,%d\n",i,j,k,l);
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	sort(ar,ar+ind,comp);
	i=0;
	while(i<ind)
	{
		printf("%d - {%d,%d,%d,%d},\n",i,ar[i].a,ar[i].b,ar[i].c,ar[i].d);
		i++;
	}
	return 0;
}