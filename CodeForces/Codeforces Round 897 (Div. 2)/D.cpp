#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
            int n, k, time = 1;
            cin >> n >> k;
            vector<int> a(n + 1), vis(n + 1, 0);
            for (int i = 1; i <= n; i++) cin >> a[i];
            if (k == 1) {
                bool iok = true;
                for (int i = 1; i <= n; i++)
                    iok &= a[i] == i;
                cout << (iok ? "YES" : "NO") << endl;
                continue;
            }
            vector<int> cnt(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                if (vis[i] != 0) continue;
                int u = i;
                set<int> new_node;
                while (true) {
                    new_node.insert(u);
                    vis[u] = time++;
                    int v = a[u];
                    if (vis[v] != 0) {
                        if (new_node.find(v) != new_node.end()) {
                            int cc = 1;
                            int n1 = u, n2 = v;
                            while (n2 != n1) {
                                cc++;
                                n2 = a[n2];
                            }
                            cnt[cc]++;
                        }
                        break;
                    }
                    u = v;
                }
            }
            cout << ((cnt[k] > 0 && accumulate(cnt.begin(), cnt.end(), 0LL) == cnt[k]) ? "YES" : "NO") << endl;
        }

    return 0;
}
