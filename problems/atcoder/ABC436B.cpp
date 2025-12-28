/*
    Task: AtCoder ABC436B
    Date: 26.12.2025
    Time: 17:32:42 CET
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
    /* Solution goes here */
    /*
n >= 3, n is odd

3
nxn matrix

write 1 in cell (0, (n - 1) / 2)
-> a[0][1] = 1


x x x
x x x
x x x
->
x 1 x
x x x
x x x

repeat:
(r, c) = last written cell,
k = last number written
if ((r - 1) mod n, (c + 1) mod n) is empty: write k + 1
i.e. a[2][2] = 2

x 1 x
x x x
x x 2
-> r, c = 2, 2; k = 2 -> next cell: a[1][0] = 3
x 1 x
3 x x
x x 2
-> r, c = 1, 0; k = 3 -> next cell: a[0][1] is filled -> next cell: a[2][0] = 4
x 1 x
3 x x
4 x 2


BUT: 3 <= n <= 99 -> we can just do the same as the problem statement tells
     */

    int n;
    cin >> n;
    vector<vi> a(n, vi(n, -1));

    int x = 0;
    int y = (n - 1) / 2;
    int k = 1;

    while (k <= n * n) {
        a[x][y] = k;
        k += 1;
        int nextX = (x - 1 + n) % n;
        int nextY = (y + 1) % n;
        if (a[nextX][nextY] == -1) {
            x = nextX;
            y = nextY;
            continue;
        }

        nextX = (x + 1) % n;
        nextY = y;
        if (a[nextX][nextY] == -1) {
            x = nextX;
            y = nextY;
            continue;
        }

        break;
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) cout << a[i][j] << " ";
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
