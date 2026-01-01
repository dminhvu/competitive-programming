/*
    Task: CSES 2431
    Date: 01.01.2026
    Time: 17:06:29 CET
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
12345678910111213141516171819202122232425
n = j-th digit from pow(10, i) - 1
num = k-th number that contains the j-th digit
num -> n / i


32 - 9 = 23
23/2 = 11-th number from 10 -> 10 + 11 = 21
64 - 9 = 55
55/2 = 27-th number

333 - 9 - 180 = 144
144/3 = 48-th number from 100 -> 100 + 48 = 148
144%3 = 0-th digit in 148 -> 8

582 - 9 - 180 = 393
393/3 = 131-th number from 100 -> 100 + 131 = 231
393%3 = 0-th digit in 231 -> 1

214 - 9 - 180 = 25
25/3 = 8-th number from 100 -> 100 + 8 = 108
25%3 = 1-th digit in 108 -> 0
    */
    ll n;
    cin >> n;

    if (n < 10) {
        cout << n << '\n';
        return;
    }

    ll a[20];

    rep(i, 1, 17) {
        ll lower = binpow(10, i - 1);
        ll upper = binpow(10, i) - 1ll;
        a[i] = (upper - lower + 1) * 1ll * i;
        // debug2(i, a[i]);
    }

    int i = 1;
    while (n > a[i]) {
        n -= a[i];
        i++;
    }

    // (n - 1) / i -> trick to pick the correct j-th number; i.e. if
    // n is divisible by i, it would be the (j + 1)-th number, so
    // we decrease n by 1 to ensure it's always the j-th number
    ll num = (n - 1) / (1ll * i);

    // because mod = 0 -> last digit, = 1 -> first digit, = 2 ->
    // 2nd digit and so on, we use (i - 1) - (n + i - 1) % i
    // -> make it become: 0 = last digit, 1 = second last
    // digit, 2 = third last digit, and so on
    int mod = (i - 1) - (n - 1) % (1ll * i);

    num += binpow(10, i - 1);
    while (mod > 0) {
        num /= 10ll;
        mod--;
    }
    cout << num % 10 << '\n';
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
