/*
    Task: Codeforces 1526B
    Date: 22.12.2025
    Time: 19:46:34 CET
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

// Type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

// Macros
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

// 1-indexed loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const ld EPS = 1e-9;
const int MOD = 998244353;

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Solution function
void solve() {
    // x = 11a + 111b + 1111c + ... + 111111111h
    // 1111 = 11*100 + 11
    // 11111 = 111*100 + 11
    // 111111 = 111*1000 + 111
    // -> x = 11x + 111y

    // 144 = 100 * 1 + 11 * 4
    int x;
    cin >> x;

    bool yes = false;
    if (x < 111) {
        yes = x % 11 == 0;
    } else {
        yes = x % 11 == 0 || x >= 111 * (x % 11);
    }

    cout << (yes ? "YES" : "NO") << "\n";
}

int main() {
    fastIO();

    int t = 1;
    cin >> t;  // Comment out if single test case

    while (t--) {
        solve();
    }

    return 0;
}
