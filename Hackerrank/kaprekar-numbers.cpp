#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair<int,int> pii;
typedef long long int ll;

bool isKaprekar(int n){
	ll sq = ((ll)n)*n;
	int* ar = new int[15];
	memset(ar, 0, 15*4);

	int count = 0;
	while(sq > 0){
		ar[count] = sq % 10;
		count++;
		sq /= 10;
	}
	if(count % 2 == 0){
		int s = count/2;
		int l = 0, r = 0;
		for(int i=0; i<s; i++)
			l = l*10 + ar[s-1-i];
		for(int i=0; i<s; i++)
			r = r*10 + ar[count-1-i];
		return (l+r == n);
	}
	else{
		int s = count / 2;
		int l = 0, r = 0;
		for(int i=0; i<s+1; i++)
			l = l*10 + ar[s-i];
		for(int i=0; i<s; i++)
			r = r*10 + ar[count-1-i];
		return (l+r == n);
	}
}

int main(){
	int p, q;
	cin >> p >> q;
	bool flag = true;
	for(int i = p; i <= q; i++){
		if(isKaprekar(i)){
			flag = false;
			cout << i << " ";
		}
	}
	if(flag)
		cout << "INVALID RANGE" << endl;
	else
		cout << endl;
	return 0;
}