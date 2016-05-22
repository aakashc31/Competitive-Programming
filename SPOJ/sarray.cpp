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

#define maxn 100050 
//since max length of a string can be 1000

char st[maxn];
int n; //length of input string
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn]; //count frequency

int phi[maxn], PLCP[maxn], LCP[maxn];

inline void countSort(int k){
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

inline void createSuffixArray(){
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

	for(int i=1; i<n; i++)
		cout << SA[i] << endl;

}


int main(){
	cin >> st;
	n = strlen(st);
	st[n++] = '$'; st[n] = '\0';
	createSuffixArray();
	return 0;
}