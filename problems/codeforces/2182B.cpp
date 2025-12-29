/*
    Task: Codeforces 2182B
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
1  1
2  2
4  5
8  10
16 21
    */
    ll pow2[25];
    pow2[0] = 1;
    rep(i, 1, 24) {
        pow2[i] = pow2[i - 1] + (1ll << (i - 1));
        debug2(i, pow2[i]);
    }

    ll a, b;
    cin >> a >> b;
    ll tmpA = a;
    ll tmpB = b;
    int cnt = 0;
    while (tmpA >= 0 || tmpB >= 0) {
        if (cnt % 2 == 1 && tmpB >= pow2[cnt]) {
            tmpB -= pow2[cnt];
        } else if (cnt % 2 == 0 && tmpA >= pow2[cnt]) {
            tmpA -= pow2[cnt];
        } else {
            break;
        }
        cnt += 1;
    }

    int ans = cnt;

    tmpA = a;
    tmpB = b;
    swap(tmpA, tmpB);
    cnt = 0;
    while (tmpA >= 0 || tmpB >= 0) {
        if (cnt % 2 == 1 && tmpB >= pow2[cnt]) {
            tmpB -= pow2[cnt];
        } else if (cnt % 2 == 0 && tmpA >= pow2[cnt]) {
            tmpA -= pow2[cnt];
        } else {
            break;
        }
        cnt += 1;
    }

    ans = max(ans, cnt);

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
