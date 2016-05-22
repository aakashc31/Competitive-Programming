#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        string a,b; cin >> a >> b;
        int alen = a.length(), blen = b.length();
        int i=0, j=0;
        string ans; ans.resize(alen + blen);
        int index = 0;
        while(i < alen && j < blen){
            if(a[i] < b[j]){
                ans[index] = a[i];
                i++;
            }
            else if(a[i] > b[j]){
                ans[index] = b[j];
                j++;
            }
            else{
                if(i+1 < alen && j+1 < blen){
                    if(a[i+1] < b[j+1])
                        ans[index] = a[i++];
                    else
                        ans[index] = b[j++];
                }
                else{
                    ans[index] = a[i];
                    i++;
                }
            }
            index++;
        }
        while(i < alen)
            ans[index++] = a[i++];
        while(j < blen)
            ans[index++] = b[j++];
        cout << ans << endl;
    }
    return 0;
}
