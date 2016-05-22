#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,k;
	cin >> n >> k;
	srand(time(NULL));
	for(int i=0; i<n+k-1;i++){
		int r = rand()%2;
		cout << r;
	}
	cout << endl;
	return 0;
}