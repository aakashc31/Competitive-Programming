#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <time.h>
#include <string.h>
#include <set>
#include <map>

#define ull unsigned long long

using namespace std;

const int MAXN = 100100;
char s[MAXN];
int n, k;
ull base = 997, p[MAXN];
ull hsh[MAXN], inv_hsh[MAXN];

ull get(int st, int fin) {
    if (st > fin) return 0;
    ull res = hsh[fin];
    if (st > 0) {
        res -= hsh[st - 1];
    }
    res *= p[n - st];
    return res;
}

ull getInv(int st, int fin) {
    if (st > fin) return 0;
    ull res = inv_hsh[st];
    res -= inv_hsh[fin + 1];
    res *= p[fin + 1];
    return res;
}

int bin(int st, int fin, int posl, int posr, int startl, int startr) {
    //cerr<<st<<" "<<fin<<"   "<<posl<<" "<<posr<<" "<<startl<<" "<<startr<<endl;
    if (st == fin) {
        return st;
    }
    int med = (st + fin + 1) / 2;
    ull A = get(startl - med + 1, posl);
    ull B = getInv(posr, startr + med - 1);
    if (A == B) {
        return bin(med, fin, posl, posr, startl, startr);
    }
    else {
        return bin(st, med - 1, posl, posr, startl, startr);
    }
}

int calc(int startl, int startr) {
    //cerr<<"calc: "<<startl<<" "<<startr<<endl;
    int prvlen = 0, res = 0;
    for (int i = 0; i <= k; i++) {
        int len = bin(prvlen, min(startl + 1, n - startr), startl - prvlen, startr + prvlen, startl, startr);
        //cerr<<i<<" "<<prvlen<<" "<<len<<endl;
        res = len;
        if (len == startl + 1) {
            break;
        }
        if(n - startr == len) {
            break;
        }
        prvlen = len + 1;
        if (i < k && prvlen == startl + 1) {
            return prvlen;
        }
        if(i < k && n - startr == prvlen) {
            return prvlen;
        }
    }
    return res;
}

ull sum(ull a) {
    ull h = a/2 + a%2;
    return (a + a - (h - 1)*2) * h / 2;
}

int bruteforce() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int l = i, r = j, diff = 0;
            while (l < r) {
                diff += (s[l] != s[r]);
                l++; r--;
                if (diff > k) {
                    break;
                }
            }
            if (diff <= k) {
                ans += j - i + 1;
            }
        }
    }
    return ans;
}

int calc2(int l, int r) {
    int res = 0, diff = 0;
    while (l >= 0 && r < n) {
        diff += (s[l] != s[r]);
        if (diff > k) {
            return res;
        }
        res++;
        l--; r++;
    }
    return res;
}

long long brute2() {
    long long ans = 0, c =0;
    for (int i = 0; i < n; i++) {
        c += (s[i] != 'a');
        int maxlen = calc2(i, i);
        ans += sum(2*maxlen - 1);

        if (i + 1 < n) {
            maxlen = calc2(i, i + 1);
            ans += sum(2*maxlen);
        }
    }
    cerr<<c<<endl;
    return ans;
}

void solve() {
    scanf("%d%d%s", &n, &k, s);
    cout<<brute2()<<endl;
}

int main() {
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i - 1] * base;
    }
    int test;
    cin>>test;
    while (test--) {
        solve();
    }
    cerr<<(double)clock() / CLOCKS_PER_SEC<<endl;
    return 0;
}