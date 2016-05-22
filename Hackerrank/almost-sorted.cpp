#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ar[100005], br[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
        br[i] = ar[i];
    }
    if(is_sorted(ar, ar+n)){
        cout << "yes" << endl;
        return 0;
    }
    sort(br, br+n);
    int count = 0;
    int left = -1, right = -1;
    for(int i=0; i<n; i++){
        if(ar[i] != br[i]){
            count++;
            if(count == 1)
                left = i;
            else if(count == 2)
                right = i;
        }
    }
    if(count == 2){
        cout << "yes" << endl;
        cout << "swap " << left + 1 << " " << right + 1 << endl;
        return 0;
    }
    
    left = 0, right = n-1;
    
    while(ar[left] == br[left])
        left++;
    while(ar[right] == br[right])
        right--;
    // cout << "left = " << left << " right = " << right << endl;
    bool flag = true;
    for(int i=right; i>left; i--){
        if(ar[i] > ar[i-1]){
            flag = false;
            break;
        }
    }
    
    if(flag){
        cout << "yes" << endl;
        cout << "reverse " << left + 1 << " " << right + 1 << endl;
        return 0;
    }
    
    cout << "no" << endl;
    
    return 0;
}
