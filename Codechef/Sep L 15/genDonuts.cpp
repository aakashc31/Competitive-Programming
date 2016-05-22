#include <bits/stdc++.h>
using namespace std;

int main(){
	int m;
	cin >> m;
	srand(time(NULL));
	int* ar = new int[m];
	int n=0;
	for(int i=0; i<m; i++){
		ar[i] = (rand()%100000)+1;
		n += ar[i];
	}
	cout << 200 << endl;
	for(int t=0; t<200; t++){
		cout << n << " " << m << endl;
		for(int i=0; i<m; i++)
			cout << ar[i] << " ";
		cout << endl;
	}
	return 0;
}