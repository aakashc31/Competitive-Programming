#include <bits/stdc++.h>
using namespace std;

inline char charAt(string s, int i){
	return s[s.length()-1-i];
}

inline char myxor(char a, char b){
	int x = (a=='0') ? 0 : 1;
	int y = (b=='0') ? 0 : 1;
	int z = x^y;
	return ((z==0) ? '0' : '1');
}

void reverse(char* st, int len){
	int i=0, j=len-1;
	while(i<j){
		swap(st[i], st[j]);
		i++;
		j--;
	}
}

int main(){
	int n,k;
	string inp;
	cin >> n >> k >> inp;
	char* st = new char[n+1];
	st[n] = '\0';
	st[0] = charAt(inp,0);
	int len = inp.length();
	if(k>n) k=n;
	for(int i=1; i<= k-1; i++)
		st[i] = myxor(inp[len-1-i], inp[len-i]);
	for(int i=k; i<=n-1; i++){
		st[i] = myxor(inp[len-1-i], inp[len-i]);
		st[i] = myxor(st[i], st[i-k]);
	}
	reverse(st, n);
	cout << st << endl;
	return 0;
}