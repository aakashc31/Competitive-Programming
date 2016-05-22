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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vvi;

int main(){
	char ch[100001];
	cin >> ch;
	int l = strlen(ch);
	ll ans = 1;
	int ar[26];
	f(i,26) ar[i] = 0;
	ar[ch[0]-'a']=1;
	f(i,l){
		if(ch[i]!=ch[0])
			ar[ch[i]-'a']++;
	}
	f(i,26) ans = ar[i]==0 ? ans : (ans*ar[i])%1000;
	cout << ans << endl;
	return 0;
}