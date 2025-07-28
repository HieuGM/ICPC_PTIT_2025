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

int n, m;
int a[maxN];
bool check(int x) {
    int cur = 0;
    FOR(i, 1, n) {
        if (a[i] >= cur) {
            if (a[i] + x < m + cur) cur = a[i];
        }
        else {
            if (a[i] + x < cur) return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    int res, l = 0, r = m;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
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