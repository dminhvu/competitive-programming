/*
    Task: Codeforces 2000E
    Date: 05.01.2026
    Time: 17:36:21 CET
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

optimal way: put highest gorillas from the middle of the board
-> maximize the number of spectacles containing the gorillas

how to count all gorillas' height from (i, j) to (i + k - 1, j + k - 1)
-> 2D prefix sum: pref[i + k - 1][j + k - 1] - pref[i - 1][j - 1]

build a map of overlapping spectacles:

n = 3
m = 3
k = 2
1 2 1
2 4 2
1 2 1

n = 3
m = 5
k = 3
1 1 2 1 1
1 1 2 1 1
1 1 2 1 1

1 1 3 1 1
1 1 3 1 1
1 1 3 1 1

-> we can build this by building a prefix sum 2D array

for i: 0..n-1
    for j:0..m-1
        for x:i..i+k-1
            for y:j..j+k-1
                cnt[x][y]++
-> O(n*m*k^2)

sort by cnt and multiply with sorted heights -> answer

optimization:
how to determine if how many cells are overlapped on cell (i, j)

number of times the spectacle "scans" through some columns:
(m - k + 1)
number of times ... some rows:
(n - k + 1)

number of times col j being "scanned" through:
some j2 such that j2 + k - 1 >= j and j2 <= j
-> j2 from j - k + 1 to j
or (j - max(0, j - k + 1) + 1)
however: j must be <= m - k
-> (min(j, m - k) - max(0, j - k + 1) + 1)
number of times row j being "scanned" through:
some i2 such that i2 + k - 1 >= i and i2 <= i
-> i2 from i - k + 1 to i
or (i - max(0, i - k + 1) + 1)
-> (min(i, n - k) - max(0, j - k + 1) + 1)

key takeaway:
- the trick is to know how to count many times a cell (i, j) is being inside a
square kxk -> similar to 2D convolution operation
    */
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    int a[w];
    rep(i, 0, w - 1) cin >> a[i];
    vll v;
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) {
            ll count = 1ll * (min(i, n - k) - max(0, i - k + 1) + 1) *
                       (min(j, m - k) - max(0, j - k + 1) + 1);
            v.PB(count);
        }
    }
    sort(all(v));
    ll ans = 0;
    sort(a, a + w);
    reverse(a, a + w);
    rep(i, 0, w - 1) {
        if (!sz(v)) {
            break;
        }
        ans += 1ll * a[i] * v.back();
        v.pop_back();
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
