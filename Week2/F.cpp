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
const int maxS = 100 * 100;
int n;
int a[maxN], b[maxN];
void solve() {
    cin >> n;
    int sum = 0;
    FOR(i, 0, n-1) {
        cin >> a[i];
        sum += a[i];
    }
    FOR(i, 0, n-1) cin >> b[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(maxS + 1, -1));
    // dp[k][c]: lượng soda tối đa chứa trong k chai với tổng dung tích c
    dp[0][0] = 0; // chọn 0 chai với tổng dt = 0 => lượng soda = 0
    FOR(i, 0, n-1) {
        for (int k = n - 1; k >= 0; --k) {
            for (int c = 0; c <= maxS - b[i]; ++c) {
                if (dp[k][c] == -1) continue;
                dp[k + 1][c + b[i]] = max(dp[k][c] + a[i], dp[k + 1][c + b[i]]); 
            }
        }
    }
    FOR(k, 1, n) {
        int res = -1;
        FOR(c, sum, maxS) {
            res = max(res, dp[k][c]);
        }
        if (res != -1) {
            cout << k << ' ' << sum - res;
            return;
        }
    }
}
HieuGM() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    cerr << "Time: " << TIME << "s.\n";
    return (0^0);
}