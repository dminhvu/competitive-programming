/*
    Task: Codeforces 2114E
    Date: 05.01.2026
    Time: 18:54:31 CET
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

given a tree of n vertices

for each vertice, print the max alterating sum from that vertex to root 0

obs: elements of alternating sum will always be odd length

can we do some dp from the root?
dp[0] = a[0]
dp[v] = max(a[v], dp[p[u]] - a[u] + a[v])
-> this means: we can either connect the vertex v with the max path from root to
vertex p[u] otherwise, we just take the vertex v
    */
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    vi g[n];
    rep(i, 0, n - 2) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].PB(v);
        g[v].PB(u);
    }

    int p[n];
    ll dp[n];
    memset(p, -1, sizeof(p));
    memset(dp, -1, sizeof(dp));
    dp[0] = a[0];
    queue<int> q;
    q.push(0);
    while (sz(q)) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dp[v] == -1) {
                ll sum = a[v];
                if (p[u] != -1) {
                    sum += dp[p[u]] - a[u];
                }
                chmax(dp[v], sum);
                chmax(dp[v], 1ll * a[v]);
                q.push(v);
                p[v] = u;
            }
        }
    }

    rep(i, 0, n - 1) { cout << dp[i] << " "; }
    cout << '\n';
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
