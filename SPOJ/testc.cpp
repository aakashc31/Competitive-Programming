#include <bits/stdc++.h>
using namespace std;

// int* func(int r){
// 	int* ar = new int[r];
// 	// int ar[r];
// 	for(int i=0; i<r; i++) ar[i] = 2*i;
// 	return ar;
// }
// struct X
// {
//     enum direction { left = 'l', right = 'r' };
// };

enum Color {RED, BLUE = 12 , GREEN};

ostream& operator<<(ostream& stream,const Color& c){
	if(c == RED)
		stream << "red";
	else if(c == BLUE)
		stream << "blue";
	else
		stream << "green";
	return stream;
}

int& test(int& y){
	cout << &y << endl;
	y++;
	return y;
}

int main(){
	Color c = BLUE;
	cout << c << endl;
	cout << RED << " " << BLUE << " " << GREEN << endl;
	
	// X x;
	// X* p = &x;
	 
	// int a = X::direction::left; // allowed only in C++11 and later
	// int b = X::left;
	// int c = x.left;
	// int d = p->left;
	
	// cout << a << " " << b << " " << c << " " << d << endl;
	int x = 10;
	int &y = test(x);
	cout << y << endl;
	cout << &x << " " << &y << endl;
	int a = 10;
	int& b = a;
	cout << &a << " " << &b << endl;
	return 0;
}