#include <bits/stdc++.h>
int D[100][100],t,n,a,m,i,j;
using namespace std;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>a;
		m=a,D[0][0]=a;
		for(i=1;i<n;i++){
			for(j=0;j<i+1;j++){
				cin>>a;
				D[i][j]=a+max(j==0?0:D[i-1][j-1],i==j?0:D[i-1][j]);
				m=max(m,D[i][j]);
			}
		}
		cout<<m<<endl;
	}
}