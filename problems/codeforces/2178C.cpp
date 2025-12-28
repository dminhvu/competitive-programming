/*
    Task: Codeforces 2178C
    Date: 27.12.2025
    Time: 15:19:43 CET
    Author: https://www.linkedin.com/in/dminhvu02
*/

#include <algorithm>
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

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
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
    /*
        Solution goes here

Given the array a[i]
In one op:
- Choose a[0], add a[0] to X, remove a[0]
- Choose a[1], subtract a[1] from X, remove a[1]

Find the maximum X
-1e9 <= a[i] <= 1e9
-> maybe can sort by a[i]

-> maybe can dp?
dp[i][0], dp[i][1] = maximum X possible when i-th child is considered, 0 is
add, 1 is subtract

if pick a[i] as first: dp[i][0] = d[i - 1][0] + a[i]

if pick a[i] as second: dp[i][1] = dp[i - 1][1] - a[i]

-4 2 3 -6

i = 0, j = 1

ans + a[0] > ans - a[1] ? no
-> ans -= a[1] -> ans = -2
j += 1 -> j = 2
i = 0, j = 2

ans + a[0] > ans - a[2] ? no
-> ans -= a[2] -> ans = -5
j += 1 -> j = 2
i = 0, j = 3

ans + a[0] > ans - a[3] ? no
-> ans -= a[3] -> ans = 1


0 1 2 3
0: is not selected
1: is selected as first
2: is selected as second


-2 -3 4 10 -9

first: -2 -5  5  15 6
second: 0  3 -3 -13 6

dp[2][1] = max(dp[1][1] + a[2], dp[0][1] - a[1] + a[2])
max(-5 + 4, -2 - -3 + 4) = 5
dp[2][2] = max(dp[1][2] - a[2], dp[0][1] - a[1] - a[2])
max(3 - 4, -2 - -3 - 4) = -3

dp[3][1] = max(5 + 10, -5 - 4 + 10) = 15
dp[3][2] = max(-3 - 10, -5 - 4 -10) = -13

dp[4][1] = max(15 + -9, 5 - 10 + -9) = 6
dp[4][2] = max(-13 - -9, 5 - 10 - -9) = 6



---

-4 2 3 -6
dp[0][1] = -4
dp[1][2] = -2

dp[1][1] = max(-4 + -2) = -6
dp[1][2] = max(-2) = -2

dp[2][1] = max(-6 + 3, -4 - 2 + 3) = -3
dp[2][2] = max(-2 - 3, -4 - 2 -3) = -5

---

7 -6 -1 -8 -8

dp[0][1] = 7

dp[1][1] = 1
dp[1][2] = 6, 7 + 6

dp[2][1] = max(1 + -1, 7 - -6 + -1) = 12
dp[2][2] = max(6 - -1, 7 - -6 - -1) = 14

dp[3][1] = max(12 + -8, 1 - -1 + -8) = 4
dp[3][2] = max(14 - -8, ) = 22


---

dp[i][1] =
- dp[i - 1][1] + a[i]
- dp[i - 2][1] - a[i - 1] + a[i]
- dp[i - 1][2] + a[i - 2] + a[i]

dp[i][2] =
- dp[i - 1][2] - a[i]
- dp[i - 2][1] - a[i - 1] - a[i]


--------

Fix one unchosen child -> what is the optimal sum of the remaining children
- Obs: all children from the right of the unchosen will contribute -a[i] to X
- Obs: all children from the first children to the unchosen will contribute
abs(a[i]) to X unless the unchosen one is the first one
    */
    int n;
    cin >> n;
    ll a[n];
    rep(i, 0, n - 1) cin >> a[i];
    ll suff[n + 1];
    suff[n] = 0;
    per(i, 0, n - 1) { suff[i] = suff[i + 1] - a[i]; }

    ll pref[n];
    pref[0] = a[0];
    rep(i, 1, n - 1) { pref[i] = pref[i - 1] + abs(a[i]); }

    ll ans = -LINF;
    rep(i, 0, n - 1) {
        ll sum = suff[i + 1];
        if (i > 0) {
            sum += pref[i - 1];
        }
        ans = max(ans, sum);
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
