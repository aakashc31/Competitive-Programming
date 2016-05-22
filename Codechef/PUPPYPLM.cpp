#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

const int maxn = 1e5+10;
const ll B = 100000007;
const ll M = 1000000009;

ll power_mod(ll n, ll p, ll modulo){
	if(p==0) return 1%modulo;
	ll a = 1, sq=n;
	while(p>0){
		if(p&1) a =(a*sq)%modulo;
		sq = (sq*sq)%modulo;
		p = p>>1;
	}
	return a;
}

const ll invB = power_mod(B, M-2, M);

ll pref[maxn];
ll suff[maxn];
//compute prefix hash and reverse hash
void pre(string& st){
	int n = st.size();
	pref[0] = (st[0]-'a'+1); suff[n-1] = (st[n-1] - 'a'+1);
	ll bpow = B;
	for(int i=1; i<n; i++){
		pref[i] = (pref[i-1] + ((st[i]-'a'+1)*bpow) % M) % M;
		suff[n-1-i] = (suff[n-i] + ((st[n-1-i]-'a'+1)*bpow) % M) % M;
		bpow = (bpow * B) % M;
	}

	// for(int i=0; i<n; i++) cout << pref[i] << " ";
	// cout << endl;
	// for(int i=0; i<n; i++) cout << suff[i] << " ";
	// cout << endl;
}

ll getRangeHash(int a, int b){
	if(a == 0)
		return pref[b];
	ll ret = (pref[b] - pref[a-1] + M) % M;
	ret = (ret * power_mod(invB, a, M))%M;
	// cout << "getRangeHash " << a << ", " << b << " = " << ret << endl; 
	return ret;
}


string st; int n,k;

// a <= b
ll getReverseRangeHash(int a, int b){
	if(b == n-1)
		return suff[a];
	ll ret = (suff[a] - suff[b+1] + M) % M; //cout << "ret = " << ret << endl;
	ret = (ret * power_mod(invB, n-1-b, M)) % M;
	// cout << "getReverseRangeHash " << a << ", " << b << " = " << ret << endl;
	return ret;
}

// maximum length x, s.t. (i-x+1...i) and rev(j..j+x-1) is same
// i<j
int binary_search(int i, int j){
	int low = 0, high = min(i+1, n-j), mid;
	ll h1, h2;
	while(low < high-1){
		mid = (low + high)/2;
		h1 = getRangeHash(j, j+mid-1);
		h2 = getReverseRangeHash(i-mid+1, i);
		if(h1 == h2)
			low = mid;
		else
			high = mid-1;
	}
	//low pe to valid hai hi, ab apan dekhenge ki low+1 pe kya scene hai!
	h1 = getRangeHash(j, j+low);
	h2 = getReverseRangeHash(i-low, i);
	// cout << "h1 = " << h1 << " h2 = " << h2 << endl;
	return (h1==h2) ? low+1 : low;
}

void testBinSrch(){
	while(1){
		string st; cin >> st; n = st.length();
		pre(st);
		int q; cin >> q;
		while(q--){
			int i,j; cin >> i >> j;
			assert(i<j);
			int x = binary_search(i,j);
			cout << x << " l = " << st.substr(i-x+1, x) << ", r = " << st.substr(j,x) << endl;
		}
		cout << "\n\n";
	}
}

// int computeForOdd(int index){
// 	int i=index-1, j=index+1, currDel = 0,x;
// 	while(i>=0 && j<n && currDel <= k){
// 		x = binary_search(i,j);
// 		cout << "i = " << i << " j = " << j << "Bin : x = " <<  x << " l = " << st.substr(i-x+1, x) << ", r = " << st.substr(j,x) << endl;
// 		currDel++;
// 		i = i-x+1, j = j+x-1;
// 		if(i==0 || j==n-1){
// 			i--,j++;
// 			break;
// 		}
// 		i-=2, j+=2;
// 	}
// 	int span = index - i;
// 	cout << "Span = " << span << endl;
// 	return span;
// }

int computeForOdd(int i, int j, int k){
	int x,currDel = 0, span=0, temp = i;
	while(currDel <= k){
		x = binary_search(i-1,j+1);
		i = i-x-1; j = j+x+1;
		if(i<0 || j>=n)
			break;
		currDel++;
	}
	span = temp-i;
	cout << "Span = " << span << endl;
	return span;
}



int main(){
	cout << invB << endl;
	int t; cin >> t;
	while(t--){
		cin >> n >> k >> st;
		pre(st);
		ll oddLen = 0;
		for(int i=0; i<n; i++){
			ll temp = computeForOdd(i,i,k); temp*=temp; oddLen+=temp;
		}
		for(int i=0; i<n-1;i++){
			ll temp = computeForOdd(i,i+1, k - (st[i]==st[i+1]?0:1)); temp*=(temp+1);oddLen+=temp;
		}
		cout << oddLen << endl;
	}
	return 0;
}