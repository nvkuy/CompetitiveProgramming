#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

queue<vector<int>> q;
set<vector<int>> vis;
vector<int> f;

inline bool shouldSkip(int a, int b, int c, int d, int m) {

    for (int i = 0; i < 8; i++) {

        int mask = (((a >> i) & 1) << 0) | (((b >> i) & 1) << 1) | (((c >> i) & 1) << 2) | (((d >> i) & 1) << 3) | (((m >> i) & 1) << 4);
        if (!f[mask]) return true;

        for (int j = 0; j < 8; j++)
            if (((a >> i) & 1) == ((a >> j) & 1) && ((b >> i) & 1) == ((b >> j) & 1) && ((m >> i) & 1) == ((m >> j) & 1))
                if (((c >> i) & 1) != ((c >> j) & 1) || ((d >> i) & 1) != ((d >> j) & 1)) return true;

    }

    return false;

}

inline void pushIfNeed(int x, int y, int d) {

    auto it = vis.lower_bound({x, y});
    if (it != vis.end() && (*it)[0] == x && (*it)[1] == y) return;
    
    vis.insert({x, y});
    q.push({x, y, d});

}

inline int bfs(int a, int b, int c, int d, int m) {

    while (!q.empty()) q.pop();
    vis.clear();

    q.push({a, b, 0});
    vis.insert({a, b});

    while (!q.empty()) {

        auto u = q.front(); 
        q.pop();

        if (u[0] == c && u[1] == d)
            return u[2];

        if (shouldSkip(u[0], u[1], c, d, m)) continue;

        int dist = u[2] + 1;
        pushIfNeed(u[0] & u[1], u[1], dist);
        pushIfNeed(u[0] | u[1], u[1], dist);
        pushIfNeed(u[0], u[1] ^ u[0], dist);
        pushIfNeed(u[0], u[1] ^ m, dist);

    }

    return -1;

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    f.assign(1 << 5, 1);
    for (int mask = 0; mask < (1 << 5); mask++) {
        if (bfs((mask >> 0) & 1, (mask >> 1) & 1, (mask >> 2) & 1, (mask >> 3) & 1, (mask >> 4) & 1) == -1)
            f[mask] = 0;
    }

    int t;
    cin >> t;
    while (t--) {

        int a, b, c, d, m;
        cin >> a >> b >> c >> d >> m;

        bool iok = true;
        for (int i = 0; i < 31; i++) {
 
            if (!iok) break;
 
            int mask = (((a >> i) & 1) << 0) | (((b >> i) & 1) << 1) | (((c >> i) & 1) << 2) | (((d >> i) & 1) << 3) | (((m >> i) & 1) << 4);
            if (!f[mask]) {
                iok = false;
                break;
            }
 
            for (int j = 0; j < 31; j++) {
                if (((a >> i) & 1) == ((a >> j) & 1) && ((b >> i) & 1) == ((b >> j) & 1) && ((m >> i) & 1) == ((m >> j) & 1)) {
                    if (((c >> i) & 1) != ((c >> j) & 1) || ((d >> i) & 1) != ((d >> j) & 1)) {
                        iok = false;
                        break;
                    }
                }
            }
 
        }
 
        if (!iok) {
            cout << -1 << endl;
            continue;
        }

        vector<int> vis(1 << 3, 0);
        int na = 0, nb = 0, nc = 0, nd = 0, nm = 0;
        for (int i = 0; i < 31; i++) {

            int mask = (((a >> i) & 1) << 0) | (((b >> i) & 1) << 1) | (((m >> i) & 1) << 2);
            if (vis[mask]) continue;

            vis[mask] = 1;
            na = (na << 1) | ((a >> i) & 1);
            nb = (nb << 1) | ((b >> i) & 1);
            nc = (nc << 1) | ((c >> i) & 1);
            nd = (nd << 1) | ((d >> i) & 1);
            nm = (nm << 1) | ((m >> i) & 1);

        }

        cout << bfs(na, nb, nc, nd, nm) << endl;

    }

    return 0;
}