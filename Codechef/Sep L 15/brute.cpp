#include <bits/stdc++.h>
using namespace std;
#define g(n) scanf("%d",&n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked
typedef long long int lli;

int ar[10000];
int pref[10000];

void computePrefixXor(int* ar, int* pref, int size){
	pref[0] = ar[0];
	for(int i=1; i<size; i++)
		pref[i] = pref[i-1]^ar[i];
}

int main(){
	int n;
	cin >> n;
	f(i,n) cin >> ar[i];
	computePrefixXor(ar, pref, n);
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i; j < n-1; j++){
			for(int k = j+1; k < n; k++){
				for(int l = k; l < n; l++){
					int r1 = pref[j];
					if(i>0) r1 ^= pref[i-1];
					int r2 = pref[l] ^ pref[k-1];
					if(r1 + r2 > ans){
						cout << " i = " << i << " j = " << j << " k = " << k << " l = " << l << endl;
						ans = r1+r2;
					}
				}
			}
		}
	}
	cout << ans << endl;
}