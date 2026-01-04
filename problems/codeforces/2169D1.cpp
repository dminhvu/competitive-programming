/*
    Task: Codeforces 2169D1
    Date: 04.01.2026
    Time: 00:38:46 CET
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
x, y, k

x: operations count
y: index to remove
k: index to query after x operations

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

y = 1 -> clear everything -> result is -1 (no k-th position number)
y = 2:
op 1:
1 3 5 7 9... -> dist = 2
op 2:
1 5 9... -> dist = 4
op 3:
1 9 17... -> dist = 8

y = 3:
op 1:
1 2 4 5 7 8 10 11 13 14 16 17 19 20 22
-> a[3] = 4, a[6] = 8 -> a[1 * 3] = 1 + 1 * 3, a[2 * 3] = 2 + 2 * 3
-> a[3 * 3] = 4 + 3 * 3
-> a[4 * 3] = 5 + 4 * 3
-> a[5 * 3] = 7 + 5 * 3
op 2:
1 2 5 7 10 11 14 16 19 20
a[3] = 2 + 1 * 3
a[2 * 3] = 5 + 2 * 3
a[3 * 3] = 10 + 3 * 3

-> a[m * y] = m * y + a[m]


obs:
everywhen we perform a removal operation, the number of elements is reduced by
N/y -> new elements count = N - N/y
-> we need to find some N, so that after x operations N will become k
i.e. N is the k-th element, after repeatedly removing N/y elements in x
operations

-> this is so fucking smart, really good observation after reading editorial

    */

    ll x, y, k;
    cin >> x >> y >> k;
    ll l = 1, r = 1e12;
    ll ans = -1;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll len = mid;
        rep(i, 1, x) { len -= len / y; }
        if (len < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
            if (len == k) {
                ans = mid;
            }
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
