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
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

int parent[maxN], sz[maxN];
int n, m;
void init() {
    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}
void join(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}
void solve() {
    cin >> n >> m;
    init();
    FOR(i, 1, m) {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }
    int cnt = 0;
    FOR(i, 1, n) {
        if (parent[i] == i) {
            cnt = max(cnt, sz[i]);
        }
    }
    cout << cnt;
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