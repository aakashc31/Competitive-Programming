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

ll ar[100];

int main(){
	int n = inp();
	for(int i=0; i<n; i++)
		ar[i] = inp();
	unordered_map<ll, int> M;
	unordered_map<ll, int>::iterator it;
	f(i,n){
		f(j,n){
			f(k,n){
				ll curr = ar[i]*ar[j] + ar[k];
				it = M.find(curr);
				if(it == M.end())
					M[curr] = 1;
				else
					M[curr] = (it->second) + 1;
			}
		}
	}
	ll ans = 0;
	f(i,n){
		f(j,n){
			f(k,n){
				if(ar[i] == 0)
					continue;
				ll curr = ar[i] * (ar[j] + ar[k]);
				it = M.find(curr);
				if(it != M.end())
					ans += (it->second);
			}
		}
	}
	cout << ans << endl;
	return 0;
}