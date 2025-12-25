/*
    Task: Codeforces 2163B
    Date: 25.12.2025
    Time: 16:26:31 CET
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

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    /* Solution goes here */
    /*
TODO: Incomplete solution
permutation p
string s: 0/1

choose l, r
if l < i < r that min(p[l], p[r]) < p[i] < max(p[l], p[r]) -> switch s[i] to 1

if x[i] == 1 then s[i] must be 1
otherwise s[i] can be any

can do at most 5 operations?
output: k
if cannot, k = -1
otherwise print k, and k queries of l, r


1 2 3
000
010

find all segments of continuous 1s
if there is 1 in the beginning/end -> cannot satisfy
if x = full 0s -> zero operation

1 3 2 4 6 5
001100
l = 2, r = 5
min(l..r) = 2, position = 3
max(l..r) = 6, position = r = 5
min(l, r) = 3
max(l, r) = 6
=> min(l..r) != min(l, r)
-> can only switch from 3..5 first, push 2..4 to remaining segments to be
processed
-> 000000 -> 000100
l = 2, r = 4
min(l..r) = 2
max(l..r) = 4
min(l, r) = 3
max(l, r) = 4
-> min(l..r) != min(l, r) -> cannot perform any operation more
-> need to find another l, r to process

---

obs: all ops from position of min to position of max can be 1
1 3 2 4 6 5
001100
-> 011100

2 1 4 3 5
-> 00110

2 5 3 1 4
-> 00100

so first we'll try to fill from min pos + 1 to max pos - 1
-> try to find a way to fill at most 1s as possible


s = set of positions that need 1
i-th element can be 1 if:
there's l and r, such that min(a[l], a[r]) < a[i] < max(a[l], a[r])
if x[i] = 1:
    l = i - 1
    r = i + 1
    if min(a[l], a[r]) < a[i] < max(a[l], a[r])
        can = true

fill 1 -> 6: can fill at most 4 elements (r - l - 1)
if can fill 1 -> 6 => all elements from 2 to 4 is no needed to fill anymore

e.g.:
1 3 2 4 6 5
001100

x[3] = 1
-> need to find a range that is: min(a[l]..a[r]) < a[3] < max(a[l], a[r])
start with l = 2, r = 4 because we need to expand that range
min(a[2]..a[4]) = 2
max(a[2]..a[4]) = 4
but a[3] = 2 -> need to decrease l, because r is already satisfied
we'll find a number that is < a[3], such that the position of that number is < l
a[3] = 2, so we can find from 1..1 -> only 1, and position of 1 is < l
l -= 1 -> l = 1
set from l + 1 to r - 1 -> s[2] = s[3] = 1
011000
-> so, range from 2 to 3 is filled, we shouldn't touch 2..3 anymore
next: x[4] = 1
can fill immediately because a[3] < a[4] < a[5]

notice that: we can expand the r on the first operation, because a[r + 1] is
greater than max(a[3], a[4])
-> reduce the number of operations needed

what if a[l] and a[r] does not satisfy in the beginning
e.g.:
1 3 2 5 4 6
000100

algo:
loop through i=1..n
if x[i] == 1 and i == 1 or i == n:
    yes = false
    break
if x[i] == 1 && s[i] == 0:
    l = i - 1
    r = i + 1
    if a[l] > a[r]:
        swap(a[l], a[r])

    min_range = min(a[l], a[r], a[i])
    max_range = max(a[l], a[r], a[i])
    while a[l] >= min_range:
        l--
        min_range = min(min_range, a[l])

    while a[r] <=


---

1 3 2 4 6 5
001100

find all segments of continous 1s

(3, 4)
min(a[3]..a[4]) = 2
max(a[3]..a[4]) = 4
-> find some l such that a[l] < min(a[l + 1]...a[r])
-> find some r such that a[r] > max(a[l]..a[r - 1])

l = 3, r = 4
a[3] = 2
a[4] = 4
min(a[2], a[5]) <= min(a[2]..a[5])
max(a[2], a[5]) >= max(a[2]..a[5])


1 3 2 4 5 6
011110
l = position of first 1
r = position of last 1
-> fill all l..r to 1
min(a[l]..a[r])
max(a[l]..a[r])

-> find some i and j such that:
- assume a[i] < a[j]
- a[i] <= min(a[l]..a[r]) and i < l
- a[j] >= max(a[l]..a[r]) and j > r

try i = 1 to min(a[l]..a[r])
if pos[i] < l and a[i] <= min(a[l]..a[r])
    found_l = true

try i = max(a[l]..a[r]) to 2e5
if pos[i] > r and a[i] >= max(a[l]..a[r])
    found_r = true

6 5 4 2 3 1
001100


1 2 3 4 8 7 6 5
0 1 1 0 0 1 1 0

1 2 3 4 5 7 6 8
0 1 1 0 0 1 1 0

    */
    int n;
    cin >> n;
    vi p(n, 0), pos(n + 1, -1);
    rep(i, 0, n - 1) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    string x;
    cin >> x;
    string s(n, '0');

    vpii ans;

    rep(k, 1, 5) {
        int first_one = -1, last_one = -1;
        rep(i, 0, n - 1) {
            if (x[i] == '1' && s[i] == '0') {
                if (first_one == -1) {
                    first_one = i;
                }
                last_one = i;
            }
        }

        if (first_one == -1 && last_one == -1) {
            // there's no 1 in the string
            cout << 0 << '\n';
            return;
        }
        if (first_one == 0 || last_one == n - 1) {
            cout << -1 << '\n';
            return;
        }

        int max_val = *max_element(p.begin() + first_one, p.begin() + last_one);
        int min_val = *min_element(p.begin() + first_one, p.begin() + last_one);

        if (min_val == 1 || max_val == n) {
            cout << -1 << '\n';
            return;
        }
        int l = -1, r = -1;

        // assume a[l] < a[r]
        rep(i, 1, min_val - 1) {
            if (pos[i] <= first_one) {
                l = pos[i] + 1;
                break;
            }
        }
        rep(i, max_val, n) {
            if (pos[i] >= last_one) {
                r = pos[i] + 1;
                break;
            }
        }

        if (l != -1 && r != -1) {
            cout << 1 << '\n';
            cout << l << " " << r << '\n';
            return;
        }

        // assume a[l] > a[r]
        l = -1, r = -1;
        rep(i, 1, min_val - 1) {
            if (pos[i] > last_one) {
                r = pos[i] + 1;
                break;
            }
        }
        rep(i, max_val + 1, n) {
            if (pos[i] < first_one) {
                l = pos[i] + 1;
                break;
            }
        }

        if (l != -1 && r != -1) {
            cout << 1 << '\n';
            cout << l << " " << r << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    fastIO();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
