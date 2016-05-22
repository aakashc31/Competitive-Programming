#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int main()
{
	lli cnt1,cnt2,x,y,t,d,rem,p1,p2,a1;
	gl(cnt1); gl(cnt2); gl(x); gl(y);
	if(x==y)
	{
		t = (cnt1+cnt2)/(x-1);
		d = (cnt2+cnt1)%(x-1);
		if(d==0) d--;
		printf("%lld\n",x*t+d);
	}
	else
	{
		if(x>y)
		{
			p1 = y;
			p2 = x;
			swap(cnt2,cnt1);
		}
		else
		{
			p1 = x;
			p2 = y;
		} //now p1 < p2, cnt1,cnt2 resp

		t = cnt1/(p1-1);
		d = cnt1%(p1-1);
		if(d==0) d--;
		a1 = t*p1 + d;
		printf("a1 = %d\n",a1);
		cnt2 -= (t - (a1/(p1*p2)));
		printf("c2 = %d\n",cnt2);
		if(cnt2 < 0)
		{
			printf("%lld\n",a1);
		}
		else
		{
			t = a1/p2;
			d = a1%p2;
			rem = p2-1-d;
			printf("rem = %d\n",rem);
			if(rem >= cnt2)
			{
				printf("%lld\n",a1+rem);
			}
			else
			{
				a1 += rem;
				cnt2 -= rem;
				t = cnt2/(p2-1);
				d = cnt2 % (p2-1);
				printf("t =%lld d =%lld, c2 = %lld, p2 = %lld\n", t,d,cnt2,p2);
				if(d==0) d--;
				a1 += (t*p2 + d);
				printf("%lld\n",a1);
			}
		}

	}
	return 0;
}