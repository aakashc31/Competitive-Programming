#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cout << n << endl;
	srand(time(NULL));
	for(int i=0; i<n; i++){
		cout << (rand()%100)-50 << " " << (rand()%100)-50 << endl;
	}
	cout << endl;
}