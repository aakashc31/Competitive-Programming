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

typedef long long int ll;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;


int main() 
{
    int ar[1000];
    int n;
    cin >> n;
    for(int i=0; i<n;i++)
        cin >> ar[i];
    sort(ar,ar+n);
    int start = 0;
    int end = n - 1;
    cout << n << endl;
    while(start <= end)
    {
        int count = 0, top = ar[start];
        fab(i,start,end)
        {
            if(ar[i] == top)
                count++;
            else
                break;
        }
        int pr = end-start+1 - count;
        if(pr == 0)
            break;
        else
            cout << end-start+1 - count << endl;
        start += count;
    }

    return 0;
}