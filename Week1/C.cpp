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
    string s;
    cin >> s;
    int pos = -1;
    FOR(i, 0, (int)s.size() - 1) {
        if (s[i] == 'A') {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << 0;
        return;
    }
    for (int i = s.size() - 1; i > pos; --i) {
        if (s[i] == 'Z') {
            cout << i - pos + 1;
            return;
        }
    }
    cout << 0;
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