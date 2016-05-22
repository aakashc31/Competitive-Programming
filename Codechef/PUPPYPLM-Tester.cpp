#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 100100;
const int MAX_K = 11;
 
const int BASE_1 = 31;
const int BASE_2 = 37;
 
const int MOD = 1000000007;
 
void readInt(int &x, int l, int r) {
  scanf("%d", &x);
 
  assert(l <= x && x <= r);
}
 
void readString(char *x, int expected_len) {
  scanf("%s", x);
 
  int len = strlen(x);
  assert(len == expected_len);
}
 
char s[MAX_N];
 
int powers[2][MAX_N];
int hashes[2][MAX_N];
int reversed_hashes[2][MAX_N];
 
int f[MAX_N];
 
void set_up() {
  powers[0][0] = powers[1][0] = 1;
 
  for (int i = 1; i < MAX_N; i++) {
    powers[0][i] = (powers[0][i - 1] * 1ll * BASE_1) % MOD;
    powers[1][i] = (powers[1][i - 1] * 1ll * BASE_2) % MOD;
  }
 
  f[1] = 1;
  for (int i = 2; i < MAX_N; i++) {
    f[i] = f[i - 2] + i;
  }
}
 
void calculate_hashes(int n, char *s) {
  hashes[0][0] = hashes[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    int c = s[i] - 'a';
 
    hashes[0][i] = (hashes[0][i - 1] + powers[0][i] * 1ll * c) % MOD;
    hashes[1][i] = (hashes[1][i - 1] + powers[1][i] * 1ll * c) % MOD;
  }
 
  reversed_hashes[0][n + 1] = reversed_hashes[1][n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    int c = s[i] - 'a';
 
    reversed_hashes[0][i] = (reversed_hashes[0][i + 1] + powers[0][n - i + 1] * 1ll * c) % MOD;
    reversed_hashes[1][i] = (reversed_hashes[1][i + 1] + powers[1][n - i + 1] * 1ll * c) % MOD;
  }
}
 
int left_bound[MAX_K];
int right_bound[MAX_K];
 
long long get_hash(int hashes[], int powers[], int n, int l, int r) {
  return ((hashes[r] - hashes[l - 1] + MOD) * 1ll * powers[n - r]) % MOD;
}
 
long long get_reversed_hash(int reversed_hashes[], int powers[], int n, int l, int r) {
  return ((reversed_hashes[l] - reversed_hashes[r + 1] + MOD) * 1ll * powers[l - 1]) % MOD;
}
 
// long long get_hash(int n, int l, int r) {
//   return get_hash(hashes[0], powers[0], n, l, r) * MOD +
//      get_hash(hashes[1], powers[1], n, l, r);
// }
 
// long long get_reversed_hash(int n, int l, int r) {
//    return get_reversed_hash(reversed_hashes[0], powers[0], n, l, r) * MOD +
//        get_reversed_hash(reversed_hashes[1], powers[1], n, l, r);
// }
 
int get_hash(int n, int l, int r) {
  return get_hash(hashes[0], powers[0], n, l, r);
}
 
int get_reversed_hash(int n, int l, int r) {
  return get_reversed_hash(reversed_hashes[0], powers[0], n, l, r);
}
 
void print_substring(int l, int r) {
  for (int i = l; i <= r; i++) {
    cerr << s[i];
  }
  cerr << "\n";
}
 
long long calculate_answer_for_center(int n, int k, int l, int r) {
  if (k < 0) {
    return 0;
  }
 
  for (int it = 0; it <= k; it++) {
    int left = 1;
    int right = n;
    int shift = 0;
 
    while (left <= right) {
      int middle = (left + right) / 2;
      if (1 <= l - middle && r + middle <= n && get_hash(n, r + 1, r + middle) == get_reversed_hash(n, l - middle, l - 1)) {
        shift = middle;
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
 
    l -= shift;
    r += shift;
    if (l == 1 || r == n) {
      break;
    } else if (it < k) {
      l -= 1;
      r += 1;
    }
  }
 
  return f[r - l + 1];
}
 
void solve() {
  int n, k;
 
  readInt(n, 1, 100000);
  readInt(k, 0, 10);
  readString(s + 1, n);
 
  calculate_hashes(n, s);
 
  long long answer = 0;
  for (int i = 1; i <= n; i++) {
    answer += calculate_answer_for_center(n, k, i, i);
    if (i + 1 <= n) {
      answer += calculate_answer_for_center(n, k - (s[i] != s[i + 1]), i, i + 1);
    }
  }
 
  cout<<answer<<endl;
}
 
int main() {
  set_up();
  int cases; readInt(cases, 1, 10);
 
  for (int i = 0; i < cases; i++) {
    solve();
  }
 
  return 0;
}