/*
    Task: AtCoder ABC439D
    Date: 03.01.2026
    Time: 23:45:31 CET
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
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    unordered_map<int, vi> um;
    rep(i, 0, n - 1) { um[a[i]].pb(i); }

    ll ans = 0;
    rep(i, 0, n - 1) {
        if (a[i] % 5 == 0) {
            int m = a[i] / 5;
            auto it1 = um[m * 3].end() -
                       lower_bound(um[m * 3].begin(), um[m * 3].end(), i);
            auto it2 = um[m * 7].end() -
                       lower_bound(um[m * 7].begin(), um[m * 7].end(), i);

            if (it1 != -1 && it2 != -1) {
                ans += 1ll * it1 * it2;
            }
        }
    }

    per(i, 0, n - 1) {
        if (a[i] % 5 == 0) {
            int m = a[i] / 5;
            auto it1 = lower_bound(um[m * 3].begin(), um[m * 3].end(), i) -
                       um[m * 3].begin();
            auto it2 = lower_bound(um[m * 7].begin(), um[m * 7].end(), i) -
                       um[m * 7].begin();

            if (it1 != -1 && it2 != -1) {
                ans += 1ll * it1 * it2;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    setup();

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
