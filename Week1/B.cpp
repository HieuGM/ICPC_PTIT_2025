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

string s;
int n, k;
int dp[maxN];
// dp[i]: so cach ghep chuoi con s[0...i - 1]
int cnt = 1;
int child[maxN][35], isEnd[maxN];
void insert(string &word) {
    int u = 0;
    for (int i = word.size() - 1; i >= 0; --i) {
        int c = word[i] - 'a';
        if (!child[u][c]) child[u][c] = cnt++;
        u = child[u][c];
    }
    isEnd[u] = 1;
}
void solve() {
    cin >> s >> k;
    n = s.size();
    FOR(i, 1, k) {
        string w;
        cin >> w;
        insert(w);
    }
    dp[0] = 1;
    FOR(i, 1, n) {
        int u = 0;
        for (int j = i - 1; j >= 0; --j) {
            int c = s[j] - 'a';
            if (!child[u][c]) break;
            u = child[u][c];
            if (isEnd[u]) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    cout << dp[n];
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