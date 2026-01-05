/*
    Task: Codeforces 2181B
    Date: 05.01.2026
    Time: 17:08:13 CET
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

in one turn:
- pick max value y from opponent
- choose one element x from ours
then:
- if x >= y -> remove y
- if x < y -> y -= x

if Alice wins:
- always pick x as the max value from ours
-> if y - x is greater than x -> Alice can never win
because: if y - x is less than or equal to x

how can Alice win?

10
19
when n = 1 and 2 * x > y

10 10
5 16


obs: one will always try to use their max and pick the opponent's max
-> this is to make the opponent's max become as minimal as possible

    */
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    rep(i, 1, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    rep(i, 1, m) {
        int x;
        cin >> x;
        b.insert(x);
    }

    int turn = 0;
    while (sz(a) && sz(b)) {
        if (turn == 0) {
            auto maxA = prev(a.end());
            auto maxB = prev(b.end());
            if (*maxA < *maxB) {
                b.insert(*maxB - *maxA);
            }
            b.erase(maxB);
        } else {
            auto maxA = prev(a.end());
            auto maxB = prev(b.end());
            if (*maxB < *maxA) {
                a.insert(*maxA - *maxB);
            }
            a.erase(maxA);
        }

        turn = 1 - turn;
    }

    if (sz(a)) {
        cout << "Alice" << '\n';
    } else {
        cout << "Bob" << '\n';
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
