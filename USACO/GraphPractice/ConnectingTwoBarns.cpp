#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &c, vector<int> &dd, vector<int> &com) {
    dd[u] = 1;
    com.push_back(u);
    for (int v : c[u])
        if (!dd[v]) dfs(v, c, dd, com);
}

int main()
{

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> c(n), cc;
        vector<int> dd(n, 0);
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            c[u].push_back(v);
            c[v].push_back(u);
        }

        set<int> com1, comn;
        for (int i = 0; i < n; i++) {
            bool need_add_end = (!dd[n - 1]);
            if (!dd[i]) {
                cc.push_back(vector<int>(0));
                dfs(i, c, dd, cc.back());
            }
            if (need_add_end && dd[n - 1]) {
                for (int u : cc.back())
                    comn.insert(u);
            }
            if (i == 0) {
                for (int u : cc.back())
                    com1.insert(u);
            }
        }

        long long ans = 2e18;
        for (auto &com : cc) {
            long long l_dis = 1e9, r_dis = 1e9;
            for (int u : com) {
                auto it = com1.upper_bound(u);
                if (it == com1.end()) it--;
                l_dis = min(l_dis, 1LL * abs(u - (*it)));
                if (it != com1.begin()) {
                    it--;
                    l_dis = min(l_dis, 1LL * abs(u - (*it)));
                }
                it = comn.upper_bound(u);
                if (it == comn.end()) it--;
                r_dis = min(r_dis, 1LL * abs(u - (*it)));
                if (it != comn.begin()) {
                    it--;
                    r_dis = min(r_dis, 1LL * abs(u - (*it)));
                }
            }
            ans = min(ans, l_dis * l_dis + r_dis * r_dis);
        }

        cout << ans << endl;

    }
    
    return 0;
}
