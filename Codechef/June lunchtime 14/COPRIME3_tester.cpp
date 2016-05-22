#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
 
using namespace std;
 
long long ans = 0;
int cnt[1000005];
int n, x;
int a[100005];
 
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) a %= b; else b %= a;
    }
    return (a + b);
}
 
int p[1000005];
 
// cnt[i] - number of elements that are equal to i 
 
int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        cnt[x]++;
    }
    for (int i = 2; i <= 1000000; ++i){
        int j = i;
        long long all = 0;
        // use method of inclusions
        while (j <= 1000000) {
            all += cnt[j];
            p[j] = i;
             j += i;
        }
        int x = i;
        bool ok = true;
        int ret = 0;
        for (int d = 2; d * d <= x; ++d)
            if (x % d == 0) {
                x /= d;
                ret++;
                if (x % d == 0) {
                    ok = false;
                    break;
                }
            }
        if (!ok) continue;
        if (x > 1) ret++;
        long long dd = 1LL * all * (all - 1) * (all - 2) / 6;
        if (ret % 2 == 1) ans += dd; else ans -= dd;
    }
    long long res = 1LL * n * (n - 1) * (n - 2) / 6 - ans;
    cout << res << endl;
}
