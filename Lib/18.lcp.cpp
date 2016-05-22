// create the LCP (longest common prefix) array on top of the suffix array.

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define maxn 100010

char st[maxn];
int n; //length of input string
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn]; //count frequency

int phi[maxn], PLCP[maxn], LCP[maxn];

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
	for(int i=0; i<n; i++)
		cout << LCP[i] << " ";
	cout << endl;
}


int main(){
	cin >> st;
	n = strlen(st);
	st[n] = '\0';
	// createSuffixArray();
	createLCP();
	return 0;
}