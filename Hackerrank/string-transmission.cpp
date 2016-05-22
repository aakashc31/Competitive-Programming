#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int lli;

ll mod = 1000000007;

ll dp[1000][1005];

lli power_mod(lli i, int p)
{
	if(p==0)
		return 1;
	else if(p%2==0)
	{
		lli half = power_mod(i,p/2);
		half = (half*half)%mod;
		return half;
	}
	else
	{
		lli half = power_mod(i,p/2);
		half = (half*half)%mod;
		half = (half*i)%mod;
		return half;
	}
}

ll fact[1005];
ll inv[1005];
ll factinv[1005];

void computeFact(){
	fact[1] = 1;
	for(ll i=2; i<1005; i++)
		fact[i] = (i * fact[i-1]) % mod;
}

void calculate_inverses()
{
	inv[1] = 1;
	factinv[1] = 1;
	ll p = mod;
	for(ll i=2; i<1005; i++)
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

ll sumTillK(ll n, ll k){
	ll ret = 0;
	for(ll i=0; i<=k; i++){
		ret += ncrMod(n,i);
		ret %= mod;
	}
	return ret;
}

void getDivisors(int n, vector<int>& div){
	for(int i=1; i*i <= n; i++){
		if (n % i == 0){
			div.push_back(i);
			if(i != (n/i) && (i!=1))
				div.push_back(n/i);
		}
	}
	sort(div.begin(), div.end());
}

ll makePeriodicInKFlips(string& s, int period, int k){
	int len = s.length();
	assert(len % period == 0);
	int numStrings = len/period;
	int* counter = new int[period];
	memset(counter, 0, 4*period);
	for(int i=0; i< len; i++){
		counter[i % period] += (s[i] - '0');
	}
	//count[j] = number of 1s in all the substrings at pos j
	ll minSum = 0;
	for(int i=0; i < period; i++){
		counter[i] = min(counter[i], numStrings - counter[i]);
		minSum += counter[i];
	}
	// cout << "period = " << period <<endl;
	// cout << "Counter: ";
	// for(int i=0; i< period; i++)
	// 	cout << counter[i] << " ";
	// cout << endl;

	int maxSum = len - minSum; //max number of flips to be made to make periodic
	if(maxSum <= k){
		ll ret = power_mod(2,period);
		// cout << "period = " << period << " ret = " << ret << endl;
		return ret;
	}
	if(k<minSum || k>maxSum){
		// cout << "period = " << period << " ret111 = " << 0 << endl;
		return 0;
	}
	//now we use knapsack wala DP -> subset sum type
	// dp[i][j] = number of ways of selecting from counter[0..i] to produce a sum of j
	// number of ways in which we can make the first i chars of all string equal using j flips
	// dp[0][j] = 0
	// dp[0][counter[0]] = 1, dp[0][numStrings - counter[0]] = 1
	// dp[j][0] = 
	// dp[i][j] = dp[i-1][j-counter[i]] + dp[i-1][j - numStrings + counter[i]] 

	for(int j=0; j <= maxSum; j++){
		dp[0][j] = 0;
	}
	dp[0][counter[0]] += 1, dp[0][numStrings - counter[0]] += 1;

	int zeroPref = 0;
	while(zeroPref < period && counter[zeroPref] == 0)
		zeroPref++;
	for(int i=0; i<zeroPref; i++)
		dp[i][0] = 1;
	for(int i=zeroPref; i<period; i++)
		dp[i][0] = 0;
	for(int i=1; i<period; i++){
		for(int j=1; j<=maxSum; j++){
			dp[i][j] = (j-counter[i] >= 0) ? dp[i-1][j-counter[i]] : 0;
			dp[i][j] += (j-numStrings+counter[i] >= 0) ? dp[i-1][j-numStrings+counter[i]] : 0;
			dp[i][j] %= mod;
		}
	}
	// cout << "DP" << endl;
	// for(int i=0; i<period; i++){
	// 	for(int j=0; j<=maxSum; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll ans = 0;
	for(int i=0; i<= k; i++){
		ans += dp[period-1][i];
		ans %= mod;
	}
	// cout << "period = " << period << " ans = " << ans << endl;
	return ans;
}

int  main(){
	computeFact();
	calculate_inverses();
	int t;
	cin >> t;
	int n,k;
	string str;
	while(t--){
		cin >> n >> k;
		cin >> str;
		if(n==1){
			if(k==0)
				cout << 1 << endl;
			else
				cout << 2 << endl;
			continue;
		}
		vector<int> div;
		getDivisors(n, div);
		vector<ll> ans(div.size(), 0);
		ll sum = 0;
		for(int i=0; i<div.size(); i++){
			ans[i] = makePeriodicInKFlips(str, div[i], k);
			for(int j=0; j<i; j++){
				if(div[i] % div[j] == 0){
					ans[i] = (ans[i] + ((mod-1)*ans[j])%mod)%mod;
				}
			}
			sum += ans[i];
			sum %= mod;
		}
		// cout << sumTillK(n,k) << " " << sum << endl;
		cout << (sumTillK(n,k) + ((mod-1)*sum)%mod)%mod << endl;
	}
	return 0;
}