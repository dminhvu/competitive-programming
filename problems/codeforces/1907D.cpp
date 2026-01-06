/*
    Task: Codeforces 1907D
    Date: 06.01.2026
    Time: 14:52:01 CET
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

initially x = 0
given n segments
l[i], r[i] = left and right endpoint of level i
after the i-th move, player must be within the i-th segment
that is: l[i] <= x <= r[i]

player is allowed to move at most k distance

1: x += d[1]
2: x += d[2]

-> abs(d[i]) <= k
for each level, store 2 values:
need[i] and max[i]
-> need[i] = minimum distance to reach i-th level
-> max[i] = maxmimum distance can reach (that is also within the segment)

1 2 3 4 5 6
1 2 3 4 5 6

cur: 1..3
next: 5..6
k = 2
-> next reachable range: 5..5, given cur = 3..3
k = 3
next reachable range: 5..6, given cur == 2..3

so: l[i] >= r[i - 1]:
maxReach[i] = min(r[i], maxReach[i - 1] + k)
minReach[i] = min(l[i], maxReach[i - 1] + k)
-> cannot reach level i if maxReach[i] < l[i]

if r[i] <= l[i - 1]:
maxReach[i] = max(r[i], minReach[i - 1] - k)
minReach[i] = max(l[i], minReach[i - 1] - k)
-> cannot reach level i if minReach[i] > r[i]

if l[i] < r[i - 1] && l[i] >= l[i - 1]

- l[i] > r[i - 1] -> min(l[i], rMax[i - 1] + k), min(r[i], rMax[i - 1] + k)
- r[i] < l[i - 1] -> max(l[i], rMin[i - 1] - k), max(r[i], rMin[i - 1] - k)
- l[i] <= r[i - 1] and l[i] > l[i - 1] -> move to the right
- l[i] <= l[i - 1] and r[i] >= r[i - 1]
-> move to range: max(l[i], lMax[i - 1] - k), min(r[i], rMax[i - 1] + k)

to reach level i-th from level (i-1)-th
need to find some point y, assuming y > x:


5
1 5
3 4
5 6
8 10
0 1

k = 2
turn 0: xMin = -7, xMax = 7
turn 1: xMax = min(7 + 7, 5), xMin = max(-7 - 7, 1) = (1, 5)
turn 2: xMin = max(1 - 7, 3), xMax = min(5 + 7, 4) = (3, 4)
turn 3:

key takeaway:
- key point is to check if a segment is reachable
- r[i - 1] + steps < l[i] or l[i - 1] - steps > r[i]
-> unreachable
    */
    int n;
    cin >> n;
    pll a[n];
    rep(i, 0, n - 1) cin >> a[i].F >> a[i].S;
    ll l = 0, r = LINF;
    ll ans = LINF;
    while (l <= r) {
        ll mid = (l + r) / 2LL;
        ll xMin = 0, xMax = 0;
        bool valid = true;
        rep(i, 0, n - 1) {
            if (xMax + mid < a[i].F || xMin - mid > a[i].S) {
                valid = false;
                break;
            }

            // calculate new xMin and xMax
            xMax = min(xMax + mid, a[i].S);
            xMin = max(xMin - mid, a[i].F);
        }

        if (!valid) {
            l = mid + 1;
        } else {
            chmin(ans, mid);
            r = mid - 1;
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
