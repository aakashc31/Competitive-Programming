#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<n; i++)
#define getcx getchar//_unlocked
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long int ll;
typedef pair<int,int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

int count1[32];

int main(){
	int n,a;
	ll ans = 0;
	n = inp();
	for(int i=0; i<n; i++){
		a = inp();
		for(int j=0; j<32; j++){
			if(a & (1<<j))
				count1[j]++;
		}
	}

	for(int i=0; i<32; i++){
		ll cnt = count1[i];
		cnt = (cnt*(cnt-1))/2;
		ans += (cnt * (1<<i));
	}

	cout << ans << endl;
	return 0;

}