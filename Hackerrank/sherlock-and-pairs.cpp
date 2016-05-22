#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
typedef long long int lli;
typedef long long int ll;

inline int inp()//fast input function
{
	lli n=0;
	int ch=getcx();int sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
	 
	while( ch >= '0' && ch <= '9' )
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
	return n;
}
int ar[100005];

int main(){
	int t,n;
	t = inp();
	while(t--){
		n = inp();
		for(int i=0; i<n; i++)
			ar[i] = inp();
		sort(ar, ar+n);
		ll ans = 0;
		int count = 1, curr = ar[0];
		for(int i=1; i<n; i++){
			if(ar[i] == curr)
				count++;
			else{
				ans += ((ll)count)*(count-1);
				count = 1;
				curr = ar[i];
			}
		}
		ans += ((ll)count)*(count-1);
		cout << ans << endl;
	}
	return 0;
}