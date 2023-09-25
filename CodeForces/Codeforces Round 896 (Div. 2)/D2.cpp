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
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        long long equal = sum / n;
        bool iok = true;
        vector<vector<pair<int, int>>> sol(n);
        vector<int> f(60, 0);
        vector<vector<set<int>>> c(60, vector<set<int>>(60));
        for (int i = 0; i < n; i++) {
            if (a[i] == equal) continue;
            for (int t1 = 0; t1 <= 33; t1++) {
                if ((1LL << t1) + a[i] == equal) {
                    sol[i].push_back({50, t1});
                    c[0][t1].insert(i);
                }
                if (a[i] - (1LL << t1) == equal) {
                    sol[i].push_back({t1, 50});
                    c[t1][0].insert(i);
                }
                for (int t2 = 0; t2 <= 33; t2++) {
                    if ((1LL << t2) - (1LL << t1) + a[i] == equal) {
                        sol[i].push_back({t1, t2});
                        c[t1][t2].insert(i);
                    }
                }
            }
        }
        for (int u = 0; u < n; u++) {
            if (a[u] == equal) continue;
            bool done = false;
            for (auto p : sol[u]) {
                if (done) break;
                pair<int, int> rp = {p.second, p.first};
                if (rp.first != 50 && rp.second != 50) continue;
                if (c[rp.first][rp.second].size() == 0) continue;
                int v = *c[rp.first][rp.second].begin();
                a[u] = a[v] = equal;
                for (auto pp : sol[v])
                    c[pp.first][pp.second].erase(v);
                done = true;
            }
            if (done) continue;
            for (auto p : sol[u]) {
                if (p.first != 50 && p.second != 50) {
                    f[p.first]++;
                    f[p.second]--;
                    done = true;
                }
            }
            if (!done) iok = false;
        }
        for (int i = 0; i < 60; i++) iok &= (f[i] == 0);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
