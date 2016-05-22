#include <bits/stdc++.h>
using namespace std;
string mult(string a, int n){
string r="";
int c=0,d;
for(int i=0;i<a.size();i++){
d=n*(a[i]-'0')+c;
r+=(d%10+'0');
c=d/10;
}
while(c>0){
r+=(c%10+'0');
c/=10;
}
return r;
}
int main(){
int n,d;
cin >>n>>d;
while(n!=0 || d!=0){
string ans = "1";
while(d--){
ans = mult(ans,n);
}
reverse(ans.begin(),ans.end());
cout<<ans<<endl;
cin>>n>>d;
}
return 0;
}