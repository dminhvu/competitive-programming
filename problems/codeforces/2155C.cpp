/*
    Task: Codeforces 2155C
    Date: 04.01.2026
    Time: 01:26:56 CET
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
const ll MOD = 676767677;

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

obs: n >= a[i] >= 1


0: left, 1: right
given the array a[n]
a[i] is count of visible wizards
a wizard j is visible at position i:
- b[j] = 0 and i > j
- b[j] = 1 and i < j

-> a[i] = sum(b[j] == 0) for j:1..i-1 + sum(b[j] == 1) for j:i+1..n
a[1] = 4 ->
b[1] = 0 or 1
b[2] = b[3] = b[4] = 1
a[2] = 4 ->
b[1] = 0

n = 4
a[1] = 1
-> b[1] = 0 or 1, b[2] = b[3] = b[4] = 0
0 0 0 0 -> a[2] = 2, a[3] = 3, a[4] = 4
1 0 0 0 -> a[2] = 1, a[3] = 2, a[4] = 3

n = 4
a[1] = 2
-> b[1] = 0 or 1, b[2] = 1, b[3] = b[4] = 0
or b[2] = b[4] = 0, b[3] = 1

0 1 0 0 -> a[2] = 2, a[3] = 2, a[4] = 3
0 0 1 0 -> a[2] = 2, a[3] = 3, a[4] = 3
0 0 0 1 ->


b[0] = 0 or 1

i = 1..n-1
    if a[i] == a[i - 1]:
        -> b[i] = 0..1
    if abs(a[i] - a[i - 1]) == 1:
        -> b[i] = 1 - b[i - 1]

- if a[i] - a[i - 1] == 1: -> b[i] is 0 and b[i - 1] is 0
- if a[i] - a[i - 1] == -1: -> b[i] is 1 and b[i - 1] is 1
- if a[i] - a[i - 1] == 0: -> b[i] and b[i - 1] is alternated (0 -> 1, 1 -> 0)

-> takeaway: try observing how a[i] changes between two consecutive elements i
and i + 1 -> construct the original values and re-check if they are valid
    */
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    vi v[2];
    v[0].pb(0);
    v[1].pb(1);
    rep(i, 1, n - 1) {
        if (a[i] - a[i - 1] == 1) {
            if (v[0].back() == 0) {
                v[0].pb(0);
            }
            if (v[1].back() == 0) {
                v[1].pb(0);
            }
        } else if (a[i] - a[i - 1] == -1) {
            if (v[0].back() == 1) {
                v[0].pb(1);
            }
            if (v[1].back() == 1) {
                v[1].pb(1);
            }
        } else if (a[i] == a[i - 1]) {
            v[0].pb(1 - v[0].back());
            v[1].pb(1 - v[1].back());
        }
    }

    rep(k, 0, 1) {
        if (sz(v[k]) != n) {
            continue;
        }

        int pref[n], suff[n];
        pref[0] = v[k][0] == 0;
        rep(i, 1, n - 1) { pref[i] = pref[i - 1] + (v[k][i] == 0); }
        suff[n - 1] = v[k][n - 1] == 1;
        per(i, 0, n - 2) { suff[i] = suff[i + 1] + (v[k][i] == 1); }

        rep(i, 0, n - 1) {
            int total = 1;
            if (i > 0) {
                total += pref[i - 1];
            }
            if (i < n - 1) {
                total += suff[i + 1];
            }
            if (total != a[i]) {
                v[k].clear();
                break;
            }
        }
    }

    int ans = (sz(v[0]) == n) + (sz(v[1]) == n);
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
