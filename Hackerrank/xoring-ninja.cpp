#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1000000007;

ll fact[100005];
ll inv[100005];
ll factinv[100005];

void computeFact(){
	fact[1] = 1;
	for(ll i=2; i<100005; i++)
		fact[i] = (i * fact[i-1]) % mod;
}

void calculate_inverses()
{
	inv[1] = 1;
	factinv[1] = 1;
	ll p = mod;
	for(ll i=2; i<100005; i++)
	{
		inv[i] = ((p - p/i)*(inv[p%i]))%p;
		factinv[i] = (inv[i] * factinv[i-1]) % mod;
	}
}

ll ncrMod(ll n, ll r){
	if(r>n) return 0;
	if(r==0) return 1;
	if(n==r) return 1;
	if(r==1) return n;
	ll ans =( fact[n] * factinv[r])%mod;
	ans = (ans * factinv[n-r])%mod;
	return ans;
}

void computeOnesInIthBit(int* ar, int size, int* ans){
	for(int i=0; i<32; i++) ans[i] = 0;
	for(int i=0; i<size; i++){
		int num = ar[i];
		for(int j=0; j<32; j++){
			if((1<<j)&num)
				ans[j]++;
		}
	}
	// cout << "computeOnesInIthBit: ";
	// for(int i=0; i<32; i++){
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
}

ll computeXorSum(int* ar, int size){
	int* onesInIthBit = new int[32];
	memset(onesInIthBit, 0, sizeof onesInIthBit);
	computeOnesInIthBit(ar, size, onesInIthBit);

	ll answer = 0;
	ll pref[100000];
	memset(pref, 0, sizeof pref);

	for(int i=0; i<32; i++){
		int k = onesInIthBit[i];
		int l = size - k;
		ll curr = 0;
		pref[0] = 1;
		for(int j=1; j<=size-1; j++)
			pref[j] = (pref[j-1] + ncrMod(l,j))%mod;
		for(int j=1; j<=k; j+=2){
			curr +=( ncrMod(k,j) * pref[size-j])%mod;
			curr %= mod;
		}
		answer = answer + ((1<<i)*(curr))%mod;
		answer %= mod;
	}
	return answer;
}

void testNcrMod(){
	computeFact();
	calculate_inverses();
	while(1){
		int n,r;
		cin >> n >> r ;
		cout << ncrMod(n,r) << endl;
	}
}
int arr[100000];
int main(){
	// testNcrMod();
	computeFact();
	calculate_inverses();
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		cout << computeXorSum(arr, n) << endl;
	}
	return 0;
}

