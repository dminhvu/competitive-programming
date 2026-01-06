/*
    Task: Codeforces 1920C
    Date: 06.01.2026
    Time: 16:46:02 CET
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

given an array a[i]
for each k = divisor of n
partition a[i] into n / k parts
if exists a number m, such that after doing a[i] % m
all subarrays become identical, i.e. a[1] == a[1 + k] == a[1 + 2*k], a[2] = a[2
+ k] == a[2 + 2*k], etc.

naive idea:
find all divisors of n
for each divisor k -> O(logn)
find all m:2..n -> O(n)
    do a[i] % m for all a[i] -> O(n)
    compare a[1]..a[1+k-1] with a[1+k]..a[1+2k-1] and so on -> O(n)

m > n (or max(a[i])) -> useless because all elements stay the same
so m will always be between 2..n

8 % 2 = 0
8 % 3 = 2
8 % 4 = 0
8 % 5 = 3
8 % 6 = 2
8 % 7 = 1
8 % 8 = 0
8 % 9 = 8

12 % 2 = 0
12 % 3 = 0
12 % 4 = 0
12 % 5 = 2
12 % 6 = 0
12 % 7 = 5
12 % 8 = 4
12 % 9 = 3
12 % 10 = 2
12 % 11 = 1
12 % 12 = 0

8 = 2^3
12 = 2^2*3
-> common divisors = 2, 2^2

for each value m: count how many splits are valid

when will a[i] % m = a[i + k] % m for some m
- a[i] % m = 0 and a[i + k] % m = 0
- when m <= min(a[i], a[i + k]) / 2

---

key takeaway:
- x mod m = y mod m -> (x - y) mod m = 0
-> m is some factor of (x - y)


x x x x x x

k = 3
0-3
1-4
2-5

k = 2
0-2
1-3
2-4
3-5

for each divisor k -> O(logn)
    calculate g = gcd(abs(x[i] - x[i + k]))
    m must be a factor of g -> g > 1 will make m exists
    */
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 0;
    rep(k, 1, n) {
        if (n % k == 0) {
            int g = 0;
            rep(j, 0, n - k - 1) { g = gcd(g, abs(a[j] - a[j + k])); }
            ans += (g == 0 || g > 1);
        }
    }

    cout << ans << '\n';
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
