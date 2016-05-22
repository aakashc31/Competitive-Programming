#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
#include<bitset>
#define test(t) while(t--)
#define cin(n) scanf("%d",&n)
#define cout(n) printf("%d\n",n)
#define rep(i,n) for(i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
#define imax (int) 1000000007
#define ill long long
#define gc getchar_unlocked
using namespace std;
 
void fcin(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
 
int main()
{
	int t,i,n;ill q;vi b;bitset<5000001> a;b.resize(5000001);a.flip();
    for(i=2;i<2236;i++)
    {
        if(a[i])
        {
            t=i*i;
            while(t<=5000000)
                {
                    a[t]=0;t+=i;
                }
        }
    }
    t=1;q=1;
    b[1]=1;
    for(i=2;i<=5000000;i++)
    {
        if(a[i]) t++;
        q=t%imax;
        q*=b[i-1];
		q%=imax;
        b[i]=(int)q;
        //cout(b[i]);
    }
    cin(t);
    test(t)
    {
        fcin(n);cout(b[n]);
    }
    return 0;
} 
