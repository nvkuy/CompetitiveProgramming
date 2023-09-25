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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<long long> ps1(n + 1, 0), ps2(n + 1, 0);
    vector<int> a1(n + 1), a2(n + 1);
    bool isFlaw = false;
    for (int i = 1; i <= n; i++) {
        cin >> a1[i];
        ps1[i] += ps1[i - 1] + a1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a2[i];
        ps2[i] += ps2[i - 1] + a2[i];
    }
    for (int i = 1; i <= n; i++)
        isFlaw |= (a1[i] + a2[i] < 0);
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (isFlaw) {
            cout << "flawed" << endl;
            continue;
        }
        if (u == v) {
            cout << 0 << endl;
            continue;
        }
        long long ans = 1e18;
        if (u < v) {
            ans = min(ans, ps1[v - 1] - ps1[u]);
            ans = min(ans, ps2[n] - (ps2[v - 1] - ps2[u]));
        } else {
            ans = min(ans, ps2[u - 1] - ps2[v]);
            ans = min(ans, ps1[n] - (ps1[u - 1] - ps1[v]));
        }
        cout << ans << endl;
    }


    return 0;
}
