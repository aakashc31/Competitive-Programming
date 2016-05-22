#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define mp make_pair
#define pb push_back


int main(){
	int t,n,m,a;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%d", &m);
		int numOnes = 0;
		for(int i=0; i<m; i++){
			scanf("%d", &a);
			if(a == 1)
				numOnes++;
		}
		int numNonOnes = m - numOnes;
		if(numOnes == m){
			cout << numOnes/2 << endl;
		}
		else if(numOnes == 0){
			cout << numNonOnes - 1 << endl;
		}
		else if(numOnes == numNonOnes - 1){
			cout << numOnes << endl;
		}
		else if(numOnes < numNonOnes-1){
			cout << numNonOnes - 1 << endl;
		}
		else{
			// cout << min(numNonOnes-1 + ((numOnes-numNonOnes+2)/2) , numOnes/2 + numNonOnes)<< endl;
			int k = numOnes, l = numNonOnes;
			int p = (k-l+1)/4;
			p  += ((k-l+1 % 4) == 0) ? 0 : 1 ;
			cout << l + 2*p - 1 << endl;
		}
	}
	return 0;
}