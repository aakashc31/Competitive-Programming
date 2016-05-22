#include <bits/stdc++.h>

using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getNum(n) scanf("%d",&n)
#define getStr(st) scanf("%s",st)

typedef long long int lli;

const int size = 100000;
const int mod = 1000000007;

int a[size];
int b[size];
int c[size];

int power_mod(int a, int p)
{
        if(p==0)
                return 1;
        int half = power_mod(a,p/2);
        lli sq = ((lli(half))*half)%mod;
        if(p&1)
                return (sq*a)%mod;
        else
                return sq;
}

int main()
{

        int n,m;
        getNum(n), getNum(m);
        int ar[n];
        f(i,n) getNum(a[i]),ar[i]=0;
        f(i,m) getNum(b[i]);
        f(i,m) getNum(c[i]);
        //

        f(i,m)
        {
                int k=b[i];
                while(k<=n)
                {
                        ar[k-1]++;
                        k+=b[i];
                }
        }
        f(i,n)
                printf("%d ",ar[i]);
        printf("\n");
        f(i,n)
        {
                a[i] = (a[i]*power_mod(c[i],ar[i]))%mod;
                printf("%d ",a[i]);
        }
        printf("\n");
        return 0;

}