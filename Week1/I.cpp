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

int n, k;
vector<int> prime(1005, 1);
vector<int> pri;
void sang() {
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= sqrt(505); ++i) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 505; j += i) {
            prime[j] = 0;
        }
    }
    for (int i = 2; i <= 505; ++i) {
        if (prime[i]) pri.pb(i);
    }
}
int legen(int n, int p) {
    int res = 0;
    for (int i = p; i <= n; i *= p) {
        res += n/i;
        if (i > n/p) break;
    }
    return res;
}
void solve() {
    int res = 1;
    for (int x : pri) {
        // cout << x << ' ';
        int cnt = legen(n, x) - legen(k, x) - legen(n - k, x);
        res *= (cnt + 1);
    }
    cout << res;
}
HieuGM() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    sang();
    while (cin >> n >> k) {
        solve();
        cout << '\n';
    }
    cerr << "Time: " << TIME << "s.\n";
    return (0^0);
}