#include <bits/stdc++.h>
using namespace std;

void getDivisors(int n, vector<int>& div){
	for(int i=1; i*i <= n; i++){
		if (n % i == 0){
			div.push_back(i);
			if(i != (n/i) && (i!=1))
				div.push_back(n/i);
		}
	}
	sort(div.begin(), div.end());
}

bool isPeriodicWithPeriodK(string s, int k){
	// assert( s.size() % k == 0);

	for(int i=0; i<s.size(); i++){
		if(s[i] != s[i%k])
			return false;
	}
	return true;
}

bool isPeriodic(string& s){
	vector<int> div;
	getDivisors(s.size(), div);
	for(int i=0; i<div.size(); i++){
		if(isPeriodicWithPeriodK(s, div[i]))
			return true;
	}
	return false;
}

int getFlipCount(string& a, string& b){
	// assert(a.size() == b.size());
	int c=0;
	for(int i=0; i<a.size(); i++){
		if(a[i] != b[i])
			c++;
	}
	return c;
}

string original;
int k;
int answer;
int counter;
void generateAllBinaryStrings(int len, string curr){
	if(curr.length() == len){
		counter++;
		// cout << counter << " : " << curr << endl;
		if((!isPeriodic(curr)) && (getFlipCount(curr, original) <= k)){
			// cout << "Satisfying : " << curr << endl;
			answer++;
		}
	}
	else{
		curr.push_back('0');
		generateAllBinaryStrings(len, curr);
		curr.pop_back();
		curr.push_back('1');
		generateAllBinaryStrings(len, curr);
	}
}	

int main(){
	cin >> k >> original;
	answer = 0;
	counter = 0;
	string curr = "";
	generateAllBinaryStrings(original.length(), curr);
	cout << "Final answer = " << answer << endl;
}