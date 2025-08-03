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

void solve() {
    int a;
    cin >> a;
    int c = a;
    a = 2 * a * a;
    for (int i = 1; i <= 100000; ++i) {
        int b = a - i * i;
        if (b <= 0) break;
        int tmp = sqrtl(b);
        if (i != c && tmp != c && tmp != i && tmp * tmp == b && tmp <= 100000) {
            // cout << i << ' ' << tmp << ' ';
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}
HieuGM() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << '\n';
    }
    cerr << "Time: " << TIME << "s.\n";
    return (0^0);
}