#include <bits/stdc++.h>
using namespace std;

#define f(i,n) 			for(int i=0; i<n; i++)
#define pb 				push_back
#define mp 				make_pair
#define fab(i,a,b) 		for(int i=a; i<=b; i++)
#define test(t) 		while(t--)
#define getcx getchar//_unlocked
#define get(n)			scanf("%d",&n)
#define getL(n)			scanf("%lld", &n)

typedef long long int 	ll;
typedef long long int 	lli;
typedef pair<int,int> 	pii;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;

#define maxn 500050  
//since max length of a string can be 1000

char st[maxn];
int n; //length of input string
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn]; //count frequency

int phi[maxn], PLCP[maxn], LCP[maxn];
int l1, l2;
void countSort(int k){
	int maxi = max(300, n),sum=0,t;
	memset(c, 0, sizeof c);
	for(int i=0; i<n; i++)
		c[i+k < n ? RA[i+k] : 0]++;
	for(int i=0; i<maxi; i++){
		t = c[i]; c[i] = sum; sum += t;
	}
	for(int i=0; i<n; i++)
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(int i=0; i<n; i++)
		SA[i] = tempSA[i];
}

void createSuffixArray(){
	int r;
	for(int i=0; i<n; i++)
		SA[i] = i, RA[i] = st[i];

	for(int k=1; k<n; k<<=1){
		countSort(k); //sort sa based on second rank, ra[sa[i]+k]
		countSort(0); //stable sort based on first rank, ra[sa[i]]
		tempRA[SA[0]] = r = 0;
		for(int i=1; i<n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for(int i=0; i<n; i++)
			RA[i] = tempRA[i];
		if(RA[SA[n-1]] == n-1) break;
	}
}

void createLCP(){
	createSuffixArray();
	phi[SA[0]] = -1; //phi(i) : the suffix which is just before the i'th suffix in suffix array. Which comes lexicographically just before i'th suffix
	for(int i=1; i<n; i++)
		phi[SA[i]] = SA[i-1];
	int l = 0;
	for(int i=0; i<n; i++){
		if(phi[i] == -1){
			PLCP[i] = 0;
			continue;
		}
		while(st[i+l] == st[phi[i]+l]) l++;
		PLCP[i] = l;
		l = max(0, l-1);
	}
	for(int i=0; i<n; i++)
		LCP[i] = PLCP[SA[i]];
}

inline bool isInFirst(int index){
	return (index>=0 && index<l1);
}

inline bool isInSecond(int index){
	return (index >= l1+1 && index < (l1+l2+1));
}

void computeLCS(){
	createLCP();
	int ret = 0;
	for(int i=1; i<n; i++){
		if((isInFirst(SA[i]) && isInSecond(SA[i-1])) || (isInSecond(SA[i]) && isInFirst(SA[i-1])))
			ret = max(ret, LCP[i]);
	}
	cout << ret << endl;
}

int main(){
	cin >> st;
	l1 = strlen(st);
	st[l1] = 'A';
	cin >> st+l1+1;
	l2 = strlen(st+l1+1);
	st[l1+l2+1] = '$';
	n = l1+l2+2;
	computeLCS();
	return 0;
}