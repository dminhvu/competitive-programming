/*
    Task: CSES 3217
    Date: 31.12.2025
    Time: 17:06:05 CET
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
const int MOD = 998244353;

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

Standing at x, y:
- (x - 2, y + 1)
- (x - 1, y + 2)
- (x + 1, y + 2)
- (x + 2, y + 1)
- (x + 2, y - 1)
- (x + 1, y - 2)
- (x - 1, y - 2)
- (x - 2, y - 1)

    */
    int n;
    cin >> n;
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int dist[n][n];
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    queue<pii> q;
    q.push(mp(0, 0));

    while (q.size()) {
        pii cur = q.front();
        q.pop();
        rep(i, 0, 7) {
            pii nxt = mp(cur.fi + dx[i], cur.se + dy[i]);

            if (nxt.fi < 0 || nxt.fi >= n || nxt.se < 0 || nxt.se >= n) {
                continue;
            }
            if (dist[nxt.fi][nxt.se] == -1) {
                dist[nxt.fi][nxt.se] = dist[cur.fi][cur.se] + 1;
                q.push(nxt);
            }
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { cout << dist[i][j] << " "; }
        cout << '\n';
    }
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
