#include <bits/stdc++.h>
using namespace std;

#define g(n) scanf("%d",&n)
// #define g(n) inp(n)
#define gl(n) scanf("%lld", &n)
#define f(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define fab(i,a,b) for(int i=a; i<=b; i++)
#define test(t) while(t--)
#define getcx getchar//_unlocked

#define isLowerAlpha(x) (x>='a' && x<='z')
#define isUpperAlpha(x) (x>='A' && x<='Z')

bool isValid(string& s){
	for(int i=0; i<s.length(); i++){
		if(isUpperAlpha(s[i]) || isLowerAlpha(s[i]) || (s[i]=='_'))
			continue;
		return false;
	}
	return true;
}

bool isJavaIdentifier(string s){
	bool ret = true;
	if(isLowerAlpha(s[0])){
		for(int i=1; i<s.length(); i++){
			if(isLowerAlpha(s[i]) || isUpperAlpha(s[i]))
				continue;
			else{
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}

bool isCppIdentifier(string s){
	if(!isLowerAlpha(s[0]))
		return false;
	int currLen = 1;
	for(int i=1; i<s.length(); i++){
		if(s[i] == '_'){
			if(currLen == 0)
				return false;
			currLen = 0;
		}
		else if(isUpperAlpha(s[i]))
			return false;
		else if(isLowerAlpha(s[i]))
			currLen++;
		else 
			return false;
	}
	if(currLen == 0)
		return false;
	return true;
}

string convertFromJavaToCpp(string s){
	vector<string> v;
	string curr = "";
	for(int i = 0; i < s.length(); i++){
		if(isUpperAlpha(s[i])){
			v.push_back(curr);
			curr = "";
			s[i] += 32;
			curr += s[i];
		}
		else
			curr += s[i];
	}
	if(curr.length() != 0)
		v.push_back(curr);

	string ret = v[0];
	for(int i=1; i<v.size(); i++)
		ret =ret + "_" + v[i];
	return ret;
}

string convertFromCppToJava(string s){
	vector<string> v;
	string curr = "";
	for(int i=0; i<s.length();i++){
		if(s[i] == '_'){
			if(v.empty()){
				v.push_back(curr);
			}
			else{
				curr[0] -= 32;
				v.push_back(curr);
			}
			curr = "";
		}
		else
			curr += s[i];
	}
	if(curr.length() != 0){
		if(!v.empty())
			curr[0] -= 32;
		v.push_back(curr);
	}
	string ret = "";
	for(int i=0; i<v.size(); i++)
		ret += v[i];
	return ret;
} 

int main(){
	string st;
	while(cin >> st){
		if(!isValid(st))
			cout << "Error!" << endl;
		else if(isCppIdentifier(st))
			cout << convertFromCppToJava(st) << endl;
		else if(isJavaIdentifier(st))
			cout << convertFromJavaToCpp(st) << endl;
		else 
			cout << "Error!" << endl;
	}
	return 0;
}