/*
    Task: Codeforces 2185F
    Date: 18.01.2026
    Time: 16:40:20 CET
    Author: https://www.linkedin.com/in/dminhvu02
*/

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) \
    cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#else
#define debug(x)
#define debug2(x, y)
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)

const int INF = 1e9 + 210903;
const ll LINF = 1e18 + 210903;
const ld EPS = 1e-9;
const ll MOD = 998244353;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

ll binpow(ll a, ll b, ll mod = LINF) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    if (!freopen("input.txt", "r", stdin)) {
        cerr << "Warning: Could not open input.txt" << endl;
    }
    if (!freopen("output.txt", "w", stdout)) {
        cerr << "Warning: Could not open output.txt for writing" << endl;
    }
#endif
}

void solve() {
    /* SOLUTION GOES HERE */
    /* ================== */
    /*

2^n cows

1 2 3 4 5 6 7 8

1 2
4 3
6 5
7 8

4 3 1 2
6 5 7 8

6 5 7 8 4 3 1 2
    */
    int n, q;
    cin >> n >> q;
    n = 1 << n;
    debug(n);
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vi pref(n + 1, 0);
    rep(i, 1, n) { pref[i] = pref[i - 1] ^ a[i]; }
    rep(i, 1, q) {
        int x, y;
        cin >> x >> y;
        int l = 1, r = n;
        int pos = 0;
        while (l < r) {
            int mid = (l + r - 1) / 2;
            int leftXOR = pref[mid] ^ pref[l - 1];
            int rightXOR = pref[r] ^ pref[mid];
            if (x <= mid) {
                leftXOR ^= a[x];
                leftXOR ^= y;
            } else {
                rightXOR ^= a[x];
                rightXOR ^= y;
            }
            if (leftXOR >= rightXOR) {
                if (x > mid) {
                    pos += mid - l + 1;
                }
            } else {
                if (x <= mid) {
                    pos += r - mid;
                }
            }
            if (x > mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << pos << '\n';
    }
}

int main() {
    setup();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
