#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(NULL));		
	int n,m; cin >> n >> m;
	cout << 1 << endl;
	cout << n << " " << m << endl;
	for(int i=0;i<n;i++){
		cout << (rand()%m)+1 << " " << (rand()%m)+1 << endl;
	}
	return 0;
}