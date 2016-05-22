#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {   
    char ch[100][101];
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> ch[i];
            sort(ch[i], ch[i]+n);
        }
        bool ans = true;
        for(int j=0; j<n; j++){
            bool flag = true;
            for(int i=0; i<n-1; i++){
                if(ch[i][j] > ch[i+1][j])
                {
                    flag = false;
                    break;
                }
            }
            ans = ans && flag;
            if(!ans)
                break;
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}