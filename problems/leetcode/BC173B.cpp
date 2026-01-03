/*
    Task: LeetCode BC173B
    Date: 03.01.2026
    Time: 15:24:41 CET
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

class Solution {
   public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 1;
        long long sum = nums[0];
        unordered_map<int, int> cnt;
        cnt[nums[0]] = 1;
        int ans = 1e9;

        rep(i, 0, n - 1) {
            while (sum < k && j < n) {
                if (!cnt[nums[j]]) {
                    sum += nums[j];
                }
                cnt[nums[j]]++;
                ++j;
            }

            if (sum >= k) {
                // debug2(i, j);
                // debug(sum);
                ans = min(ans, j - i);
            }

            cnt[nums[i]]--;
            if (!cnt[nums[i]]) {
                sum -= nums[i];
            }
        }

        if (ans == 1e9) {
            ans = -1;
        }

        return ans;
    }
};

void solve() {
    /* SOLUTION GOES HERE */
    /* ================== */
    vi nums = {6, 6, 11};
    int k = 12;

    int n = nums.size();
    int j = 1;
    long long sum = nums[0];
    unordered_map<int, int> cnt;
    cnt[nums[0]] = 1;
    int ans = 1e9;

    rep(i, 0, n - 1) {
        while (sum < k && j < n) {
            if (!cnt[nums[j]]) {
                sum += nums[j];
            }
            cnt[nums[j]]++;
            ++j;
        }

        if (sum >= k) {
            // debug2(i, j);
            // debug(sum);
            ans = min(ans, j - i);
        }

        cnt[nums[i]]--;
        if (!cnt[nums[i]]) {
            sum -= nums[i];
        }
    }

    if (ans == 1e9) {
        ans = -1;
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
