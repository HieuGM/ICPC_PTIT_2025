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

const int MOD = 998244353;
const int maxN = 1e6 + 5;

int n, k;
int a[maxN];
int binpow(int a, int p) {
    int res = 1;
    a %= MOD;
    while (p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return res;
}
int xuly(vector<int> &s) {
    int sz = s.size();
    vector<int> dp(sz + 1, 0); // dp[i] Lưu tổng số cách chọn từ 0 ... i-1
    dp[0] = 1; // không chọn phần tử nào
    if (sz >= 1) dp[1] = (1 + s[0]) % MOD; // chọn phần tử đầu tiên
    FOR(i, 2, sz) {
        // dp[i - 1]: số cách chọn đã hợp lệ, không chọn phần tử i - 1
        // s[i - 1] * dp[i - 2]: chọn phần tử i - 1
        dp[i] = dp[i - 1] + s[i - 1] * dp[i - 2] % MOD;
        dp[i] %= MOD;
    }
    return dp[sz] % MOD;
}
void solve() {
    cin >> n >> k;
    map<int, int> freq;
    FOR(i, 0, n - 1) {
        cin >> a[i];
        freq[a[i]]++;
    }
    /*
    |x - y| = k khi và chỉ khi
    x đồng dư y mod k
    => cần tính toán dựa trên các nhóm có cùng số dư khi chia cho k 
    */
    map<int, vector<int>> mp;
    for (auto &p : freq) {
        int val = p.fi;
        mp[val % k].pb(val);  // phân thành từng nhóm
    }
    int ans = 1;
    for (auto p : mp) {
        vector<int> v = p.se; 
        sort(FULL(v));
        int i = 0, sz = v.size();
        int cnt = 1;
        while (i < sz) {
            vector<int> s;
            // Với mỗi phần tử v[i], có 2 ^ freq[v[i]] - 1 cách chọn (trừ tập rỗng)
            s.pb((binpow(2, freq[v[i]]) - 1 + MOD) % MOD);
            int j = i + 1;
            while (j < sz && v[j] - v[j - 1] == k) { // Tìm những phần tử liền kề nhau có hiệu = k
                s.pb((binpow(2, freq[v[j]]) - 1 + MOD) % MOD);
                ++j;
            }
            // H ta cần đếm số cách chọn sao cho không có 2 phần tử nào liền kề nhau trong s, với trọng số của phần tử i là s[i]
            cnt = (cnt * xuly(s)) % MOD;
            i = j;
        }
        ans = (ans * cnt) % MOD;
    }
    // trừ đi cách chọn rỗng
    cout << (ans - 1 + MOD) % MOD;
}
HieuGM() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    cerr << "Time: " << TIME << "s.\n";
    return (0^0);
}