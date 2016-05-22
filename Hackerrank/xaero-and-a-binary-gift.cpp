#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string a,b;
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << "-1" << endl;
    }
    else{
        int d1 = 0, d2 = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]){
                if(b[i] == '0')
                    d1++;
                else
                    d2++;
            }
        }
        if(d1 != d2)
            cout << "-1" << endl;
        else
            cout << d1 << endl;
    }
    return 0;
}
