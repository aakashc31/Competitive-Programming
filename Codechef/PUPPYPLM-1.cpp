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
const ll invB = 868852467; //B^(-1) % M
ll pref[maxn]; ll suff[maxn];
ll bpower[maxn], binvpower[maxn];

void set_up(){
	bpower[0] = binvpower[0] = 1;
	for(int i=1; i<maxn; i++){
		bpower[i] = (bpower[i-1] * B) % M;
		binvpower[i] = (binvpower[i-1] * invB) % M;
	}
}

char st[maxn]; int n,k;
//compute prefix hash and reverse hash
void pre(){
	pref[0] = (st[0]-'a'+1); suff[n-1] = (st[n-1] - 'a'+1);
	for(int i=1; i<n; i++){
		pref[i] = (pref[i-1] + ((st[i]-'a'+1)*bpower[i])) % M;
		suff[n-1-i] = (suff[n-i] + ((st[n-1-i]-'a'+1)*bpower[i])) % M;
	}
}

inline ll getRangeHash(int a, int b){
	if(a == 0)
		return pref[b];
	ll ret = (pref[b] - pref[a-1] + M) % M;
	ret = (ret * binvpower[a])%M;
	return ret;
}

// a <= b
inline ll getReverseRangeHash(int a, int b){
	if(b == n-1)
		return suff[a];
	ll ret = (suff[a] - suff[b+1] + M) % M;
	ret = (ret * binvpower[n-1-b]) % M;
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
	h1 = getRangeHash(j, j+low); h2 = getReverseRangeHash(i-low, i);
	return (h1==h2) ? low+1 : low;
}


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
	// cout << "Span = " << span << endl;
	return span;
}

int main(){
	set_up();
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n); scanf("%d",&k); scanf("%s",st);
		pre();
		ll oddLen = 0;
		for(int i=0; i<n; i++){
			ll temp = computeForOdd(i,i,k); temp*=temp; oddLen+=temp;
			if(i!=n-1){
				temp = computeForOdd(i,i+1, k - (st[i]==st[i+1]?0:1)); temp*=(temp+1);oddLen+=temp;
			}
		}
		printf("%lld\n", oddLen);
	}
	return 0;
}