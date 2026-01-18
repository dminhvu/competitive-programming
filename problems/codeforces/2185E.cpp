/*
    Task: Codeforces 2185E
    Date: 18.01.2026
    Time: 15:32:05 CET
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

n robots
m spikes
k instructions

left/right 1 unit


1 2 3
4 5
RR

    */
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, m - 1) cin >> b[i];
    string s;
    cin >> s;
    map<int, int> mp;
    vi c(k + 1, 0);
    int cur = 0;
    rep(i, 0, k - 1) {
        cur += (s[i] == 'L' ? -1 : 1);
        debug(cur);
        if (!mp.count(cur)) {
            mp[cur] = i + 1;
        }
    }
    sort(all(a));
    sort(all(b));
    rep(i, 0, n - 1) {
        int right = lower_bound(all(b), a[i]) - b.begin();
        debug2(a[i], right);
        int minToDie = INF;
        if (right < m) {
            int rightToDie = b[right] - a[i];
            if (mp.count(rightToDie)) {
                chmin(minToDie, mp[rightToDie]);
            }
        }

        if (right > 0) {
            int left = right - 1;
            int leftToDie = b[left] - a[i];
            if (mp.count(leftToDie)) {
                chmin(minToDie, mp[leftToDie]);
            }
        }

        if (minToDie <= k) {
            c[minToDie]++;
            debug(minToDie);
        }
    }
    rep(i, 1, k) {
        c[i] += c[i - 1];
        debug(c[i]);
    }
    rep(i, 1, k) { cout << n - c[i] << " "; }
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
