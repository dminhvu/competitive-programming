/*
    Task: CSES 1625 - Grid Path Description
    Date: 01.01.2026
    Time: 18:40:25 CET
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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const ll LINF = LLONG_MAX;
const ll NLINF = LLONG_MIN;
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

bool vis[7][7];
int row[7], col[7];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n = 48;
int ans = 0;
int s[50];

void dfs(int i, int j, int p = 0) {
    if (i == 6 && j == 0) {
        if (p == n) {
            ans++;
        }
        return;
    }

    rep(k, 0, 3) {
        int nextI = i + dx[k], nextJ = j + dy[k];

        auto shouldGo = [&]() {
            if (s[p] != 4 && k != s[p]) {
                return false;
            }

            if (nextI < 0 || nextI > 6 || nextJ < 0 || nextJ > 6) {
                return false;
            }

            if (vis[nextI][nextJ]) {
                return false;
            }

            if ((nextI == 0 || nextI == 6) &&
                (nextJ > 0 && !vis[nextI][nextJ - 1] && nextJ < 6 &&
                 !vis[nextI][nextJ + 1])) {
                return false;
            }

            if ((nextJ == 0 || nextJ == 6) &&
                (nextI > 0 && !vis[nextI - 1][nextJ] && nextI < 6 &&
                 !vis[nextI + 1][nextJ])) {
                return false;
            }

            if (i == 5 && nextI == 5 && col[6] == 6) {
                if (nextJ == 5) {
                    return false;
                }
            }

            if (j == 5 && nextJ == 5 && row[0] == 6) {
                if (nextI == 1) {
                    return false;
                }
            }

            if (nextI > 0 && nextI < 6 && nextJ > 0 && nextJ < 6) {
                if (vis[nextI - 1][nextJ] && vis[nextI + 1][nextJ] &&
                    !vis[nextI][nextJ - 1] && !vis[nextI][nextJ + 1]) {
                    return false;
                }
                if (!vis[nextI - 1][nextJ] && !vis[nextI + 1][nextJ] &&
                    vis[nextI][nextJ - 1] && vis[nextI][nextJ + 1]) {
                    return false;
                }
            }

            if (nextI > 0 && nextJ < 6) {
                if (vis[nextI - 1][nextJ + 1] && !vis[nextI - 1][nextJ] &&
                    !vis[nextI][nextJ + 1]) {
                    return false;
                }
            }

            if (nextI > 0 && nextJ > 0) {
                if (vis[nextI - 1][nextJ - 1] && !vis[nextI - 1][nextJ] &&
                    !vis[nextI][nextJ - 1]) {
                    return false;
                }
            }

            if (nextI < 6 && nextJ < 6) {
                if (vis[nextI + 1][nextJ + 1] && !vis[nextI + 1][nextJ] &&
                    !vis[nextI][nextJ + 1]) {
                    return false;
                }
            }

            if (nextI < 6 && nextJ > 0) {
                if (vis[nextI + 1][nextJ - 1] && !vis[nextI + 1][nextJ] &&
                    !vis[nextI][nextJ - 1]) {
                    return false;
                }
            }

            return true;
        };

        if (shouldGo()) {
            vis[nextI][nextJ] = true;
            row[nextI]++;
            col[nextJ]++;
            dfs(nextI, nextJ, p + 1);
            vis[nextI][nextJ] = false;
            row[nextI]--;
            col[nextJ]--;
        }
    }
}

void solve() {
    /* SOLUTION GOES HERE */
    /* ================== */
    rep(i, 0, n - 1) {
        char c;
        cin >> c;
        if (c == '?') {
            s[i] = 4;
        } else if (c == 'U') {
            s[i] = 0;
        } else if (c == 'L') {
            s[i] = 1;
        } else if (c == 'D') {
            s[i] = 2;
        } else if (c == 'R') {
            s[i] = 3;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    vis[0][0] = true;
    row[0] = col[0] = 1;

    dfs(0, 0);

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
