#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define FULL(a) a.begin(), a.end()
#define FOR(i, a, b) for(int i=a; i<=b; ++i)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define HieuGM signed main
#pragma GCC optimize("Ofast,03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

int C[105][105];
void pre() {
    FOR(i, 0, 60) {
        C[i][0] = C[i][i] = 1;
        FOR(j, 1, i - 1) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}
void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    string res;
    while (a || b) {
        if (!a) {
            res.pb('b');
            --b;
        }
        else if (!b) {
            res.pb('a');
            --a;
        }
        else {
            int cnt = C[a + b - 1][a - 1];
            if (cnt >= k) {
                res.pb('a');
                --a;
            } else {
                res.pb('b');
                k -= cnt;
                --b;
            }
        }
    }
    cout << res;
}
HieuGM() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    pre();
    // cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    cerr << "Time: " << TIME << "s.\n";
    return (0^0);
}