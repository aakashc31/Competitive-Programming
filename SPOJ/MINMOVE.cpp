#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define maxn 200050

char st[maxn];
int n; //length of input string
int RA[maxn], tempRA[maxn];
int SA[maxn], tempSA[maxn];
int c[maxn]; //count frequency
int phi[maxn], PLCP[maxn], LCP[maxn];

void countSort(int k){
	int maxi = max(300, n);
	memset(c, 0, sizeof c);
	
	for(int i=0; i<n; i++)
		c[i+k < n ? RA[i+k] : 0]++;
	int sum = 0;
	for(int i=0; i<maxi; i++){
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	//cumulative sum. Now c[i] denotes number of elements in RA less than i
	for(int i=0; i<n; i++){
		int index = SA[i]+k < n ? RA[SA[i]+k] : 0;
		tempSA[c[index]++] = SA[i];
	}
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
		for(int i=1; i<n; i++){
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		}
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

int main(){
	ios::sync_with_stdio(false);
	int t=1,l;
	while(t--){
		cin >> st;
		n = strlen(st);
		for(int i=0; i<n; i++)
			st[n+i] = st[i];
		l=n; n<<=1; st[n] = '$'; n++;
		createLCP();
		n--;
		int i=0;
		while(SA[i] >= l)
			i++;
		while(i+1 <= n){
			if(SA[i+1] >= l)
				break;
			if(LCP[i+1] >= l)
				i++;
			else
				break;
		}
		cout << SA[i] << endl;
	}
	return 0;
}	