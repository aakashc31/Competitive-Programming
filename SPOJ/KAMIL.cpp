#include <bits/stdc++.h>
using namespace std;int main(){char s[25];int t=10,a;while(t--){cin>>s;a=1;for(int i=0;i<strlen(s);i++)if(s[i]=='T'||s[i]=='D'||s[i]=='L'||s[i]=='F')a<<=1;cout<<a<<endl;}}