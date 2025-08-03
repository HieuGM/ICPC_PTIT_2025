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
void solve() {
    cin >> n >> m;
    set<pii> p;
    p.insert({1, n});
    int res = 0;
    while (m--) {
        char c;
        cin >> c;
        if (c == 'A') {
            int x;
            cin >> x;
            bool ok = 0;
            for (auto it = p.begin(); it != p.end(); ++it) {
                int l = it->se - it->fi + 1; // độ dài có
                if (l >= x) {
                    int st = it->fi, en = st + x - 1;
                    auto cur = *it;
                    p.erase(it);
                    if (en < cur.se) {
                        p.insert({en + 1, cur.se}); // thêm vào đoạn bên phải nếu thừa
                    }
                    ok = 1;
                    break;
                }
            }
            if (!ok) ++res;
        }
        else {
            int st, en;
            cin >> st >> en;
            // hợp nhất với đoạn ghế trống liền kề bên trái
            auto it = p.lower_bound({st, 0}); // tìm đoạn bắt đầu bằng st
            if (it != p.begin()) {
                auto pre = it;
                --pre;
                if (pre->se >= st - 1) { // nếu trùng hoặc liền kề
                    st = min(st, pre->fi);
                    en = max(en, pre->se);
                    p.erase(pre);
                }
            }
            // hợp nhất với đoạn ghế trống liền kề bên phải
            while (1) {
                it = p.lower_bound({st, 0});
                if (it == p.end()) break;
                if (it->fi <= en + 1) {
                    en = max(en, it->se);
                    p.erase(it);
                }
                else break;
            }
            // thêm lại đoạn trống vào set
            p.insert({st, en});
        }
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