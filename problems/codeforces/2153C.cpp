/*
    Task: Codeforces 2153C
    Date: 04.01.2026
    Time: 02:44:57 CET
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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
key takeaway:
- triangle inequality
- polygon inequality
    */
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];

    if (n == 3) {
        if (a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[2] + a[0] > a[1] &&
            (a[0] == a[1] || a[1] == a[2] || a[2] == a[0])) {
            cout << a[0] + a[1] + a[2] << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    unordered_map<int, int> um;
    rep(i, 0, n - 1) um[a[i]]++;

    vpii v;
    for (auto d : um) {
        v.pb(mp(d.fi, d.se));
    }

    sort(rall(v));

    ll base = 0;
    vll odd;
    for (auto d : v) {
        int k = d.se / 2;
        base += 1ll * k * d.fi;

        if (d.se & 1) {
            odd.pb(d.fi);
        }
    }

    if (base == 0) {
        cout << 0 << '\n';
    } else {
        ll ans = 0;
        for (auto x : odd) {
            if (2ll * base > x) {
                chmax(ans, 2ll * base + x);
            }
        }

        rep(i, 0, sz(odd) - 2) {
            if (2ll * base + odd[i + 1] > odd[i]) {
                chmax(ans, 2ll * base + odd[i] + odd[i + 1]);
            }
        }

        for (auto d : v) {
            if (d.se >= 2 && base - d.fi > 0) {
                chmax(ans, 2ll * base);
            }
        }

        cout << ans << '\n';
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
