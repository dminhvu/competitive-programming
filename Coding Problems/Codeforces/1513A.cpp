#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, k; cin >> n >> k;
        if (k > (n - 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        int fi = 1, se = n;
        rep(i,n) {
            if (k == 0) break;
            if (fi > se) break;
            cout << fi << " ";
            if (fi != se) {
                cout << se << " ";
                k--;
            }
            fi++;
            se--;
        }
        for(int i = se; i >= fi; i--) cout << i << " ";
        cout << '\n';
    }
    return 0;
}