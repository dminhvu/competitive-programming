/*
    Task: Codeforces 1931E
    Date: 06.01.2026
    Time: 13:02:08 CET
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
10^m -> the final number must be longer than m digits
-> for every number, count the digits after removing all trailing zeros
however, players must play by turn and Anna plays first
so, Anna will try to reverse trailing-zero numbers
Sasha will try to combine a trailing-zero numbers with some number
    */
    int n, m;
    cin >> n >> m;
    pii a[n];
    auto countDigits = [](int num) {
        int cnt = 0;
        while (num > 0) {
            num /= 10;
            ++cnt;
        }

        return cnt;
    };

    auto countTrailingZeroes = [](int num) {
        int cnt = 0;
        while (num > 0 && num % 10 == 0) {
            num /= 10;
            ++cnt;
        }

        return cnt;
    };

    int totalDigits = 0;
    int turn = 0;
    rep(i, 0, n - 1) {
        cin >> a[i].S;
        a[i].F = countTrailingZeroes(a[i].S);
    }
    sort(a, a + n);
    reverse(a, a + n);
    rep(i, 0, n - 1) {
        int num = a[i].S;
        int digits = countDigits(num);
        if (a[i].F > 0) {
            if (turn == 0) {
                digits -= a[i].F;
            }
            turn = 1 - turn;
        }
        totalDigits += digits;
    }

    cout << (totalDigits > m ? "Sasha" : "Anna") << '\n';
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
