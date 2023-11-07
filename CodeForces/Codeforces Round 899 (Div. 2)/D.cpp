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

const int MAX_BIT = 20;

vector<long long> a, cnt, ans;
vector<vector<int>> c;
vector<vector<long long>> f0, f1;
long long n;

void buildF(int u, int par) {
    cnt[u]++;
    for (int v : c[u]) {
        if (v == par) continue;
        buildF(v, u);
        cnt[u] += cnt[v];
    }
    for (int bit = 0; bit <= MAX_BIT; bit++) {
        if ((a[u] >> bit) & 1) {
            f0[u][bit] += (1LL << bit) * cnt[u];
            for (int v : c[u]) {
                if (v == par) continue;
                f1[u][bit] += f1[v][bit];
                f0[u][bit] += f1[v][bit];
            }
        } else {
            f1[u][bit] += (1LL << bit) * cnt[u];
            for (int v : c[u]) {
                if (v == par) continue;
                f1[u][bit] += f0[v][bit];
                f0[u][bit] += f0[v][bit];
            }
        }
    }
}

void cal(int u, int par, vector<long long> parF0, vector<long long> parF1) {
    for (int bit = 0; bit <= MAX_BIT; bit++) {
        if ((a[u] >> bit) & 1) {
            ans[u] += parF1[bit];
            ans[u] += f1[u][bit];
        } else {
            ans[u] += parF0[bit];
            ans[u] += f0[u][bit];
        }
    }
    vector<long long> tf0(MAX_BIT + 1, 0), tf1(MAX_BIT + 1, 0);
    for (int v : c[u]) {
        if (v == par) continue;
        for (int bit = 0; bit <= MAX_BIT; bit++) {
            tf0[bit] += f0[v][bit];
            tf1[bit] += f1[v][bit];
        }
    }
    for (int v : c[u]) {
        if (v == par) continue;
        vector<long long> nParF0(MAX_BIT + 1, 0), nParF1(MAX_BIT + 1, 0);
        long long other = n - cnt[v];
        for (int bit = 0; bit <= MAX_BIT; bit++) {
            if ((a[u] >> bit) & 1) {
                nParF0[bit] += (1LL << bit) * other;
                nParF0[bit] += parF1[bit];
                nParF0[bit] += tf1[bit] - f1[v][bit];
                nParF1[bit] += parF1[bit];
                nParF1[bit] += tf1[bit] - f1[v][bit];
            } else {
                nParF1[bit] += (1LL << bit) * other;
                nParF0[bit] += parF0[bit];
                nParF0[bit] += tf0[bit] - f0[v][bit];
                nParF1[bit] += parF0[bit];
                nParF1[bit] += tf0[bit] - f0[v][bit];
            }
        }
        cal(v, u, nParF0, nParF1);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.assign(n + 1, 0);
        c.clear();
        c.resize(n + 1);
        cnt.assign(n + 1, 0);
        f0.assign(n + 1, vector<long long>(MAX_BIT + 1, 0));
        f1.assign(n + 1, vector<long long>(MAX_BIT + 1, 0));
        ans.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        buildF(1, 0);
        cal(1, 0, vector<long long>(MAX_BIT + 1, 0), vector<long long>(MAX_BIT + 1, 0));
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
