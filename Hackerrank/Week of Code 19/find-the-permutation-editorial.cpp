#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();

int n;
ll k;

int main()
{
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
}

int mid;

const int maxn = 2000001;
bool used[maxn];
vector<int> p;

vector<int> g[maxn];

void inverse_all()
{
    reverse(used, used + n);
    reverse(g, g + n);
    for (int &x: p)
        x = n - 1 - x;
    forn (i, n)
        for (int &x: g[i])
            x = n - 1 - x;
}

void connect(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void disconnect(int a, int b)
{
    assert(g[a].back() == b);
    g[a].pop_back();
    assert(g[b].back() == a);
    g[b].pop_back();
}

void append(int x)
{
    used[x] = true;
    if (!p.empty())
        connect(x, p.back());
    p.push_back(x);
}

void rewind(int x)
{
    assert(x == p.back());
    p.pop_back();
    if (!p.empty())
        disconnect(x, p.back());
    used[x] = false;
}

inline ll mul(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    if (INFL / a + 1 > b)
        return min(a * b, INFL);
    else
        return INFL;
}

inline ll sum(ll a, ll b)
{
    return min(a + b, INFL);
}

ll ways_block_1(int l)
{
    for (int i = mid - 1; i > l; --i)
    {
        for (int v: g[i])
            if (v != i + mid && v != i + mid + 1)
                return 0;
    }
    return 1;
}

int cdeg[maxn];
int rem_deg[maxn];

ll ways_block_2(int l, int r, int type)
{
    fill(cdeg + l + mid + 1, cdeg + r + mid + 2, 0);
    cdeg[mid] = 0;
    fill(rem_deg + l, rem_deg + r + 1, 0);

    cdeg[r + mid + 1] = 1;

    for (int i = r; i >= l; --i)
    {
        int match = i + mid;
        if (l > 0 && i == l)
            match = -1;
        bool matched = (i == l && type != 1 && type != 3);

        rem_deg[i] = 2 - sz(g[i]);
        if (i == r)
            --rem_deg[i];

        for (int v: g[i])
        {
            if (i == r && v == i + mid + 1 && type == 3)
            {
                ++rem_deg[i];
                continue;
            }
            if (v == match)
            {
                matched = true;
                ++cdeg[v];
                continue;
            }
            if (v < i + mid + 1 || v > r + mid + 1)
                return 0;
            ++cdeg[v];
        }
        if (!matched)
        {
            if (i > l || (i == 0 && type != 0))
            {
                --rem_deg[i];
                ++cdeg[match];
            }
        }
    }

    if (cdeg[mid] > 2)
        return 0;
    for (int i = l + mid + 1; i <= r + mid + 1; ++i)
        if (cdeg[i] > 2)
            return 0;
    for (int i = l; i <= r; ++i)
        if (rem_deg[i] < 0)
            return 0;

    ll res = 1;
    int avail = 0;

    for (int i = r; i >= l; --i)
    {
        avail += 2 - cdeg[i + mid + 1];
        if (i == l && type == 1)
            --avail;
        assert(avail <= 2);
        if (rem_deg[i] > 0 && rem_deg[i] < avail)
            res = mul(res, avail);
        avail -= rem_deg[i];
        if (avail < 0)
            return 0;
    }
    return res;
}

ll ways()
{
    if (sz(p) == n)
        return 1;
    if (p.back() == mid)
    {
        ll res = 0;
        int nx = 0;
        if (sz(p) > 1 && p[sz(p) - 2] == 0)
            nx = n - 1;
        if (used[nx])
            return 0;
        append(nx);
        res = ways();
        rewind(nx);
        if (sz(p) == 1)
            res = mul(res, 2);
        return res;
    }

    int end = p[0];
    bool inv = false;

    if (end == mid)
    {
        inv = p[1] < mid;
        if (inv)
            inverse_all();

        ll res = 0;

        for (end = 0; end < mid; ++end)
        {
            bool can0 = false;
            if (p[0] == mid)
                can0 = true;
            if (!used[0] && !used[mid])
                can0 = true;
            if (!used[mid] && p.back() == 0 && sz(p) + 1 == n)
                can0 = true;
            if (!used[n - 1] && !used[mid])
                can0 = true;
            if (!used[mid] && p.back() == n - 1 && sz(p) + 1 == n)
                can0 = true;

            if (can0)
            {
                res = sum(res, mul(ways_block_1(end), ways_block_2(0, end, 0)));
            }
        }

        if (inv)
            inverse_all();
        return res;
    }

    inv = end > mid;
    if (inv)
    {
        inverse_all();
        end = n - 1 - end;
    }

    bool can0 = false, can1 = false;
    if (p[0] == mid)
        can0 = true;
    if (!used[0] && !used[mid])
        can0 = true;
    if (!used[mid] && p.back() == 0 && sz(p) + 1 == n)
        can0 = true;
    if (!used[n - 1] && !used[mid])
        can0 = true;
    if (!used[mid] && p.back() == n - 1 && sz(p) + 1 == n)
        can0 = true;

    if (used[mid] && p[0] != mid)
        can1 = true;
    int rem1 = 2 - sz(g[0]) - (p[0] == 0);
    int rem2 = 2 - sz(g[n - 1]) - (p[0] == n - 1);
    if (!used[mid] && rem1 > 0 && rem2 > 0 && sz(g[0]) + sz(g[n - 1]) < 2)
        can1 = true;

    ll res = 0;
    if (can0)
    {
        res = sum(res, mul(ways_block_1(end), ways_block_2(0, end, 0)));
    }
    if (can1)
    {
        res = sum(res, mul(ways_block_1(end), ways_block_2(0, end, 1)));
        for (int i = 1; i <= end; ++i)
        {
            res = sum(res, mul(mul(ways_block_1(end), ways_block_2(i, end, 2)), ways_block_2(0, i - 1, 3)));
        }
    }
    if (inv)
        inverse_all();
    return res;
}

void expand(int N)
{
    int pos = find(p.begin(), p.end(), n - 1) - p.begin();
    forn (i, n)
        if (p[i] >= mid)
            p[i] += (N - n) / 2;
    vector<int> chain;
    for (int i = mid; i < N / 2; ++i)
    {
        chain.push_back(i);
        chain.push_back(i + N / 2 + 1);
    }
    if (pos == 0 || p[pos - 1] != mid - 1)
    {
        reverse(chain.begin(), chain.end());
    }
    else
    {
        ++pos;
    }
    p.insert(p.begin() + pos, chain.begin(), chain.end());
    n = N, mid = N / 2;
}

int solve()
{
    cin >> n >> k;
    --k;
    mid = n / 2;

    p.clear();
    fill(used, used + n, false);
    forn (i, n)
        g[i].clear();

    if (n % 2 == 0)
    {
        if (k == 0)
        {
            forn (i, mid)
            {
                p.push_back(mid - i);
                p.push_back(n - i);
            }
        }
        else if (k == 1)
        {
            forn (i, mid)
            {
                p.push_back(mid + i + 1);
                p.push_back(i + 1);
            }
        }
        else
        {
            cout << -1 << '\n';
            return 0;
        }
        forn (i, sz(p))
        {
            if (i)
                cout << ' ';
            cout << p[i];
        }
        cout << '\n';
        return 0;
    }
    if (n == 1)
    {
        if (k != 0)
            cout << -1 << '\n';
        else
            cout << 1 << '\n';
        return 0;
    }

    int _n = n;
    n = min(n, 131);
    mid = n / 2;

//    ll orig_k = k;
    forn (pos, n)
    {
        int left = 0, right = n;
        if (!p.empty())
        {
            if (p.back() < mid)
                left = p.back() + mid;
            else if (p.back() > mid)
                right = p.back() - mid + 1;
        }
        for (int i = left; i < right; ++i)
        {
            if (used[i])
                continue;
            if (pos > 0 && abs(i - p.back()) < mid)
                continue;
            append(i);
            ll w = ways();
            if (w > k)
                break;
            k -= w;
            rewind(i);
        }
        if (sz(p) != pos + 1)
        {
            if (pos == 0)
            {
                cout << -1 << '\n';
//                cerr << orig_k - k << " permutations only" << '\n';
                return 0;
            }
            assert(false);
        }
    }
    if (_n > n)
        expand(_n);
    forn (i, n)
    {
        if (i)
            cout << ' ';
        cout << p[i] + 1;
    }
    cout << '\n';
    return 0;
}