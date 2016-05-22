#include <bits/stdc++.h>
using namespace std;

bool isPandigital(int a, int b, int n){
	int p = a*b;
	int count[10];
	memset(count, 0, sizeof count);
	while(a>0){
		count[a%10]++;
		a/=10;
	}
	while(b>0){
		count[b%10]++;
		b/=10;
	}
	while(p>0){
		count[p%10]++;
		p/=10;
	}
	for(int i=1; i<=n; i++){
		if(count[i] != 1)
			return false;
	}
	for(int i=n+1; i<=9; i++){
		if(count[i] > 0)
			return false;
	}
	if(count[0] > 0)
		return false;
	return true;
}

int main1(int n){
	set<int> s;
	for(int i=1; i<=1000;i++){
		for(int j=i+1; j<=1000;j++){
			int pp = (int)log10(i)+(int)log10(j)+(int)log10(i*j)+3;
			if(pp != n)
				continue;
			if(isPandigital(i,j,n)){
				cout << i << " " << j << " "<< i*j << endl;
				s.insert(i*j);
			}
		}
	}
	int sum = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++)
		sum += *it;
	cout << sum << "\n----------------\n"; 
	return 0;
}

int main(){
	for(int i=7; i<=7; i++){
		main1(i);
	}
	return 0;
}