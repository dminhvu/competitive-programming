/*
    Task: CSES 3399
    Date: 31.12.2025
    Time: 15:55:54 CET
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
TODO: Not AC yet
2 3 4
2 3 4

4 3 2
2 4 3
    */
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO" << '\n';
    } else {
        int countEqual = n - (a + b);

        if (n - countEqual > 0 && (a == 0 || b == 0)) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            vi v1, v2;
            rep(i, 1, countEqual) v1.pb(i), v2.pb(i);
            int x = countEqual + 1;
            int y = n;
            rep(i, 1, a) {
                v1.pb(y);
                v2.pb(x);
                x++;
                y--;
            }
            rep(i, 1, b) {
                v1.pb(y);
                v2.pb(y + 1);
                y--;
            }
            for (auto x : v1) cout << x << " ";
            cout << '\n';
            for (auto x : v2) cout << x << " ";
            cout << '\n';
        }
    }
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
