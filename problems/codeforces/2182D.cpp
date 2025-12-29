/*
    Task: Codeforces 2182D
    Date: 29.12.2025
    Time: 15:06:19 CET
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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const ll LINF = LLONG_MAX;
const ll NLINF = LLONG_MIN;
const ld EPS = 1e-9;
const int MOD = 998244353;

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
TODO: To upsolve, not AC yet
Given an array of size n + 1
a[i] = decorations of i-th box

A permutation is fair if there's no case which both a[0] and a[i] is empty

In one operation:
- p1 takes 1 dec from box a[1]: a[1] -= 1
- p2 takes 1 dec from box a[2]: a[2] -= 1
until all decorations are hung up


count number of fair permutations


1 2 1 0

how about counting number of unfair permutations:
when is a permutation unfair:
a[0] must be 0 -> how many cases?
(n - 1) / a[0] + 1 cases?


n = 1:
a[1] > 0? -> 1 fair permutation

n = 2:
1 1 1

a[1] -= 1
a[2] -= 1

unfair occurs when: at some a[i]: a[i] == 0 and sum


count number of ways to distribute a[0] to some a[i]

such that a decreasing sequence is formed and each pair of adjacent numbers's
difference is at most 1 and last element must be >= 1


a[0] + .. + a[n]


1 1 2 4

1 2 3 4
2 3 3 4
2 3 4 4
3 3 3 4
3 3 4 4

1 4 4 4

dp[i][j]: count of ways to form an increasing sequence at i-th element
so that the remaining a[0] is j

max = 4
1 1 3 4

3 4 4 4


1 1 2

count max range that a[i] can be

if a[i] >= n

0 1 2

0 0 1
0 1 1
1 1 1
1 1 2
1 2 2
1 2 3
2 2 2
2 2 3
2 3 3
3 3 3

0 0 0 1
0 0 1 1
0 1 1 1
1 1 1 1
1 1 1 2
1 1 2 2
1 2 2 2
2 2 2 2
1

dp[sum] = 0
dp[sum + a[0]] = ?

    */
    int n;
    cin >> n;
    ll a[n + 1];
    rep(i, 0, n) cin >> a[i];
    ll mx[n + 1];
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        if (a[i] == 0) {
            a[i] += 1;
            a[0] -= 1;
        }
        if (a[0] < 0) {
            cout << 0 << '\n';
            return;
        }
    }

    ll p = a[0];
    per(i, 1, n) {
        ll l = 0, r = p;
        if (i < n) r = min(r, mx[i + 1]);
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll sum = 0;
            rep(j, 1, n) { sum += max(0ll, mid - a[j]); }

            if (p >= sum) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        mx[i] = l;
        debug(l);
        p -= max(0ll, l - a[i]);
        debug(p);
    }

    ll ans = 1;
    rep(i, 1, n) debug2(a[i], mx[i]);
    rep(i, 1, n) { ans *= max(0ll, (mx[i] - max(1ll * i, a[i]) + 1)); }

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
