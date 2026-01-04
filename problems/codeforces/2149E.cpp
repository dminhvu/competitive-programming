/*
    Task: Codeforces 2149E
    Date: 04.01.2026
    Time: 04:08:59 CET
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

TODO: Re-implement

i = 0, j = 0
while j - i < r:

    j++


    */
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];

    map<int, int> has;
    set<int> s;

    int j = 0;
    ll ans = 0;
    int mark = -1;
    rep(i, 0, n - 1) {
        while (j < n && j - i < r && (j - i < l || sz(s) < k)) {
            has[a[j]]++;
            s.insert(a[j]);
            j++;
            if (sz(s) == k && mark < i) {
                mark = j;
            }
        }

        while (j < n && sz(s) == k && s.count(a[j])) {
            has[a[j]]++;
            s.insert(a[j]);
            j++;
        }

        ans += max(0, j - mark);

        if (r == 6) {
            debug2(i, j);
            debug(ans);
        }
        has[a[i]]--;
        if (has[a[i]] == 0) {
            s.erase(a[i]);
        }
    }

    cout << ans << '\n';
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
