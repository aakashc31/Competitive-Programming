// post contest
#include <bits/stdc++.h>
using namespace std;


#define f(i,n)          for(int i=0; i<n; i++)
#define pb              push_back
#define mp              make_pair
#define fab(i,a,b)      for(int i=a; i<=b; i++)
#define test(t)         while(t--)
#define getcx getchar//_unlocked
#define get(n)          scanf("%d",&n)
#define getL(n)         scanf("%lld", &n)

typedef long long int   ll;
typedef long long int   lli;
typedef pair<int,int>   pii;
typedef vector<int>     vi;
typedef vector<vi>      vvi;

inline ll inp()//fast input function
{
    lli n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
     
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
    return n;
}

const ll modulo = 1e9 + 7;
ll dp[2][1000010];
ll a[1000010];
ll p[1000010];
ll n,l,k;
ll ans;

bool cmp(const int& x, const int& y){
    return (mp(a[x],x) < mp(a[y],y));
}
ll ceil_div(ll a, ll b){
    if(a%b)
        return (a/b)+1;
    return a/b;
}
void calc(int j, int i){
    ll c = l/n;
    if(i < l%n)
        c++;
    ll t = (c-j+1 + modulo) % modulo;
    ans += (t*(dp[j&1][i]))%modulo;
    ans %= modulo;
}

int main(){
    n = inp(); l = inp(); k = inp();
    f(i,n) a[i] = inp(), p[i] = i;
    sort(p, p+n, cmp);
    k = min(k, ceil_div(l,n));
    for(int i=0; i<n; i++){
        dp[1][i] = 1;
        calc(1,i);
    }
    ll curr, sum, pointer;
    // cout << __LINE__ << " YO" << endl;
    for(int j=2; j<=k; j++){
        pointer = 0, sum = 0;
        for(int i=0; i<n; i++){
            curr = p[i];
            // cout << __LINE__ << " YO " << curr << " " << pointer << endl;
            while(pointer < n && a[p[pointer]] <= a[curr])
                sum = (sum + dp[1 - (j&1)][p[pointer++]]) % modulo;
            dp[j&1][curr] = sum;
            calc(j,curr);
        }
    }
    cout << ans << endl;
    return 0;
}