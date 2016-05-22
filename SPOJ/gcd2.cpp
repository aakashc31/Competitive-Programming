// too long
#include <stdio.h>
#include <cstring>
#define v(n) scanf("%d",&n)
#define e(q) scanf("%s",q)
typedef long long int lli;
typedef int f;
void d(char q[],f z,f y){f c=0;for(f i=z; i<=y; i++){f w=q[i]-'0';if(c!=0){w=c*10+w;q[i]=w/2+'0';c=w%2;}else{if(w==1){q[i]='0';c=1;}else if(w!=0){q[i]=w/2+'0';c=w%2;}}}}
lli sl(char q[],f z,f y)
{
	lli ret=0;
	for(f i=z; i<=y; i++)
	{
		ret=ret*10+(q[i]-'0');
	}
	return ret;
}
f x(char q[],f z,f y,f m)
{
	if(y-z < 18)
	{
		lli nr=sl(q,z,y);
		f ret=(nr%m);
		return ret;
	}
	else
	{
		f a=(q[y]-'0')%2;
		d(q,z,y);
		while(z<y && q[z]=='0')
			z++;
		f hd=x(q,z,y,m);
		f k=(2*hd)%m;
		k=(k+a)%m;
		return k;
	}
}
f g(f a,f b)
{
	if(a<b)
		return g(b,a);
	if(b==0)
		return a;
	else
		return g(b,a%b);
}
f main()
{
	f t;
	v(t);
	while(t--)
	{
		char q[255];
		f a;
		e(q);
		v(a);
		f c=x(q,0,strlen(q)-1,a);
		printf("%d\n",g(a,c));
	}
	return 0;
}
