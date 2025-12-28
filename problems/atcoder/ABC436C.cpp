/*
    Task: AtCoder ABC346C
    Date: 26.12.2025
    Time: 19:00:22 CET
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

(r, c) can be placed if:
- no cells placed at (r - 1, c - 1)
- no cells placed at (r, c - 1)
- no cells placed at (r + 1, c - 1)
-> no cells placed at (x, c - 1) if x < r
- (r - 1, c)
- (r - 1, c + 1)
- ...

so, mahnattan distance must > 2
binary search for (x, y) such that x >= r - 1 and y >= c - 1
or:
search for if such a pair of (x, y) where x = r - 1 -> r + 1, y = c - 1 -> c + 1
exists yet
    */
    int n, m;
    cin >> n >> m;
    int ans = 0;
    set<pii> s;
    rep(i, 1, m) {
        int r, c;
        cin >> r >> c;
        bool yes = true;
        rep(x, r - 1, r + 1) {
            rep(y, c - 1, c + 1) {
                if (s.count({x, y})) {
                    yes = false;
                    break;
                }
            }
            if (!yes) {
                break;
            }
        }

        if (yes) {
            ans += 1;
            s.insert({r, c});
        }
    }

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
